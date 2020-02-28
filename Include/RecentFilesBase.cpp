// RecentFilesBase.cpp : Implementation of CRecentFilesBase
#include "stdafx.h"
#include "RecentFilesBase.h"
#include "AppRegKey.h"
#include "Encrypt.h"

// --------------------------------------------------------------------------
//	Description: This function allows will set the recent file list key 
//  All the recent files will be stored under it.
//	Parameters:
//		BSTR bstrFileName: Name of the file to add
//
// -----------------------------------------------------------------------------
void CRecentFilesBase::Init(LPCTSTR szRecentFileLocation, bool bEncryptMRUList)
{
	m_bstrRecentFileKey = szRecentFileLocation;

	m_bEncryptMRUList = bEncryptMRUList;
}

// --------------------------------------------------------------------------
//	Description: This function allows the user to add a file into the collection
//	of recent files, this file will be stored in recent file list key
//	HKCU\\Software\\InstallShield\\<Product Name>\\<Recent File Key>
//
//	Parameters:
//		BSTR bstrFileName: Name of the file to add
//		BSTR *pbstrFileName: Return Value, Name of the file added
//
//	Returns: Name of the added file
// --------------------------------------------------------------------------
STDMETHODIMP CRecentFilesBase::Add(BSTR bstrFileName, BSTR *pbstrFileName)
{
	_ASSERTE(VALID_BSTR(bstrFileName));
	CHECK_OUT_POINTER(pbstrFileName);

	// If NULL just return
	CComBSTR bstr(bstrFileName);
	if (bstr.Length() == 0)
		return S_OK;

	TRY_ATL
	{
		hrx hr = GetRecentFilesList();
		hr = RemoveIfFileExist(bstr);
		m_vecRecentFiles.insert(m_vecRecentFiles.begin(), bstr);
		*pbstrFileName = bstr.Detach();
		hr = SaveRecentFiles();
	}
	CATCH_ATL

	return S_OK;
}


// --------------------------------------------------------------------------
//	Description: This function allows the user to remove a file from the recent
//	file list key in registry. User can provide either the file name to remove
//	or the index.
//
//	Parameters:
//		VARIANT vItem: FileName or Index of the file to be removed
//
// --------------------------------------------------------------------------
STDMETHODIMP CRecentFilesBase::Remove(VARIANT vItem)
{
	hrx hr = GetRecentFilesList();
	if (m_vecRecentFiles.empty())
		return S_OK;

	TRY_ATL
	{
		VECITERATOR itStart = m_vecRecentFiles.begin();
		const VECITERATOR itEnd = m_vecRecentFiles.end();
		switch(vItem.vt)
		{
			case VT_BSTR:
				_ASSERTE(VALID_BSTR(vItem.bstrVal));
				hr = RemoveIfFileExist(vItem.bstrVal);
				break;
			case VT_I2:
				hr = IndexInRange(vItem.iVal);
				m_vecRecentFiles.erase(itStart + (vItem.iVal - 1));
				break;
			case VT_I4:
				hr = IndexInRange(vItem.lVal);
				m_vecRecentFiles.erase(itStart + (vItem.lVal - 1));
				break;
			default:
				hr = E_INVALIDARG;
		}
		hr = SaveRecentFiles();
	}
	CATCH_ATL

	return S_OK;
}

// --------------------------------------------------------------------------
//	PRIVATE FUNCTIONS
// --------------------------------------------------------------------------
//	Description: This function allows the user to clear the recent file list
//	collection
// --------------------------------------------------------------------------
inline HRESULT CRecentFilesBase::Clear()
{
	m_bInitFileList = false;
	m_vecRecentFiles.clear();
	return S_OK;
}


// --------------------------------------------------------------------------
inline HRESULT CRecentFilesBase::IndexInRange(long nItem)
{
	if (nItem < 1 || nItem > m_vecRecentFiles.size())
		return E_INVALIDARG;

	return S_OK;
}

// --------------------------------------------------------------------------
HRESULT CRecentFilesBase::GetRecentFilesList()
{
	TRY_ATL
	{
		if (!m_bInitFileList)
		{
			ATLASSERT(m_bstrRecentFileKey);

			Clear();

			USES_CONVERSION;
			HRESULT hr = HRESULT_FROM_WIN32(CAppRegKey::EnumValues(
				HKEY_CURRENT_USER, OLE2T(m_bstrRecentFileKey), m_vecRecentFiles));

			//If Failed this means key is not there, there can be other problems, but more possiblity of no having key
			hrx hReturn = S_OK;
			if(FAILED(hr))
			{
				hReturn = HRESULT_FROM_WIN32(CAppRegKey::CreateRegKey(
					HKEY_CURRENT_USER, OLE2T(m_bstrRecentFileKey), KEY_CREATE_SUB_KEY));
			}

			//	Remove any empty strings ""
			hReturn = RemoveEmptyValues();

			//	No need to enumerate again so set this flag
			m_bInitFileList = true;
		}
	}
	CATCH_ATL

	return S_OK;
}

// --------------------------------------------------------------------------
HRESULT CRecentFilesBase::SaveRecentFiles()
{
	TRY_ATL
	{
		//Go inside this if only if collection was ever constructed
		if (m_bInitFileList)
		{
			ATLASSERT(m_bstrRecentFileKey);

			USES_CONVERSION;

			//Must Clear the registry of all the previous values
			hrx hr = HRESULT_FROM_WIN32(CAppRegKey::DeleteAllValues(HKEY_CURRENT_USER, OLE2T(m_bstrRecentFileKey)));

			COMBSTRVECTOR::iterator itStart = m_vecRecentFiles.begin();
			COMBSTRVECTOR::iterator itEnd = m_vecRecentFiles.end();

			int nCount = 0;

			while (itStart != itEnd && nCount < 5)
			{
				TCHAR szValueName[10] = {0};
				_stprintf(szValueName, _T("%d"), nCount + 1);

				CComBSTR& bstrName = *itStart;

				EncryptString(bstrName, true);
	
				hr = HRESULT_FROM_WIN32(CAppRegKey::SetRegKeyValue(HKEY_CURRENT_USER, OLE2T(m_bstrRecentFileKey), szValueName, bstrName));
				++nCount, ++itStart;
			}
		}
	}
	CATCH_ATL

	return S_OK;
}

// --------------------------------------------------------------------------
HRESULT CRecentFilesBase::RemoveIfFileExist(CComBSTR bstrFileName)
{
	VECITERATOR itStart = m_vecRecentFiles.begin();
	const VECITERATOR itEnd = m_vecRecentFiles.end();

	CComBSTR bstrFile;
	bstrFileName.ToUpper();
	while(itStart != itEnd)
	{
		bstrFile = *itStart;
		bstrFile.ToUpper();
		if (bstrFile == bstrFileName)
		{
			//Since I break here my itStart and itEnd are valid, otherwise I have to
			//get them fresh.
			m_vecRecentFiles.erase(itStart);
			break;
		}
		++itStart;
	}

	return S_OK;
}

// --------------------------------------------------------------------------
HRESULT CRecentFilesBase::RemoveEmptyValues()
{
	VECITERATOR itStart = m_vecRecentFiles.begin();
	VECITERATOR itEnd = m_vecRecentFiles.end();

	while(itStart != itEnd)
	{
		CComBSTR& bstrValue = *itStart;
		if (bstrValue.Length() == 0)
		{
			m_vecRecentFiles.erase(itStart);
			//Get the fresh value of iterators
			itStart = m_vecRecentFiles.begin();
			itEnd = m_vecRecentFiles.end();
		}
		else
		{
			EncryptString(bstrValue, false);

			++itStart;
		}
	}
	return S_OK;
}

// --------------------------------------------------------------------------
void CRecentFilesBase::EncryptString(CComBSTR& bstrName, bool bEncrypt)
{
	if(m_bEncryptMRUList)
	{
		USES_CONVERSION;

		TCHAR szOutputValue[1024] = {0};

		CEncrypt encyptionObject;

		bool bRetVal = false;

		if(bEncrypt)
			bRetVal = encyptionObject.EncryptString(OLE2T(bstrName), szOutputValue);
		else
			bRetVal = encyptionObject.DecryptString(OLE2T(bstrName), szOutputValue);

		ATLASSERT(bRetVal != false);

		bstrName = szOutputValue;
	}
}