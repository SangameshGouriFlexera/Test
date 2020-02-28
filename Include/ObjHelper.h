#ifndef _OBJ_HELPER_H
#define _OBJ_HELPER_H

#include "is.h"
#include "hrx_new.h"
#include "pathx.h"

_IS_BEGIN

//------------------------------------------------------------------------------
//
//	Description: CreateObject
//
//	Parameters: 
//		 CComObject<T> **pObject
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
template <typename T>
static HRESULT CreateObject(CComObject<T> **pObject)
{
	CHECK_OUT_POINTER(pObject);
	hrx hr = CComObject<T>::CreateInstance(pObject);
	return S_OK;
}

//------------------------------------------------------------------------------
//
//	Description: GetObjectInterface
//
//	Parameters: 
//		 ItemType **pVal
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
template <typename T, typename ItemType>
static HRESULT GetObjectInterface(ItemType **pVal)
{
	CComObject<T> *pObject = NULL;
	hrx hr = CComObject<T>::CreateInstance(&pObject);

	return pObject->QueryInterface(pVal);
}

//------------------------------------------------------------------------------
template <class TCollection, class TInterface, class TEnumVariant = IEnumVARIANT, 
		typename TCount = unsigned long, typename TCountPointer = unsigned long>
class CEnumerator
{
public:
    CEnumerator(TCollection* pCollection)
    {
		CComPtr<IUnknown> spUnk;
        hrx hr = pCollection->get__NewEnum(&spUnk);
		hr = spUnk.QueryInterface(&m_spEnum);
    }
    bool Next(CComPtr<TInterface>& spItem)
    {
        spItem.Release();

        CComVariant varItem;
        TCount lFetched;
        hrx hr = m_spEnum->Next(1, &varItem, (TCountPointer*)&lFetched);
        if (lFetched == 0)
            return false;

        if (V_VT(&varItem) == VT_DISPATCH)
        {
            CComPtr<IDispatch> spDisp = V_DISPATCH(&varItem);
            hr = spDisp.QueryInterface(&spItem);
        }
		else if (V_VT(&varItem) == VT_UNKNOWN)
		{
			CComPtr<IUnknown> spUnknown = V_UNKNOWN(&varItem);
            hr = spUnknown.QueryInterface(&spItem);
		}
        else
        {
            hr = E_FAIL;
        }
        return true;
    }

private:
    CEnumerator(const CEnumerator& pEnumerator);
    CEnumerator& operator=(const CEnumerator& pEnumerator);

    CComPtr<TEnumVariant> m_spEnum;
};

//------------------------------------------------------------------------------
//
//	Description: CopyFileToTempFolder
//
//	Parameters: 
//		 BSTR bstrOriginalFileName -  Full path of File to be copiied
//		 BSTR *pbstrTempFileName,  -  Full path of File in Temp folder
//		 LPCTSTR lpszFileDefault   - Name used to generate temp File 
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
// --------------------------------------------------------------------------
static DWORD CopyFileToTempFolder(BSTR bstrOriginalFileName, BSTR *pbstrTempFileName,
	LPCTSTR lpszFileDefault = NULL)
{
	_ASSERTE(VALID_BSTR(bstrOriginalFileName));
	CHECK_OUT_POINTER(pbstrTempFileName);

	TRY_WIN32
	{
		using namespace is; 
		stringw strTempPath;
		if (!::GetTempPath(MAX_PATH, strTempPath.get_buffer(_MAX_PATH)))
			throw win32_exception();
	
		pathx pthFile = (LPCTSTR)strTempPath;
		pthFile += (LPCTSTR)pathx(lpszFileDefault).file();

		stringw strTempFileName =  (LPCTSTR)pthFile;
		if (lpszFileDefault == NULL)
		{
			if (!::GetTempFileName(strTempPath, _T("wac"), 0, strTempFileName.get_buffer(_MAX_PATH)))
				throw win32_exception();
		}
		
		stringw strOriginalFileName(bstrOriginalFileName);
		if(!::CopyFile(strOriginalFileName, strTempFileName, false))
			throw win32_exception();

		DWORD dwFileAttributes = ::GetFileAttributes(strTempFileName);
		if (dwFileAttributes == -1)
			throw win32_exception();

		if(dwFileAttributes & FILE_ATTRIBUTE_READONLY)
			::SetFileAttributes(strTempFileName, dwFileAttributes & ~FILE_ATTRIBUTE_READONLY);

		*pbstrTempFileName = strTempFileName.copy();
	}
	CATCH_WIN32

	return ERROR_SUCCESS;
}

//	----------------------------------------------------------------------------
static HRESULT DeleteFile(BSTR bstrFileName)
{
	_ASSERTE(VALID_BSTR(bstrFileName));
	if (! ::SysStringLen(bstrFileName))
		return S_OK;

	//	Check for the existence of the file before trying to delete it.
	is::pathx pthFile(bstrFileName);
	if (! pthFile.exists())
		return S_OK;

	is::stringw strFileName(bstrFileName);
	DWORD dwErrorCode = ::DeleteFile(strFileName);
	if (! dwErrorCode)
		return HRESULT_FROM_WIN32(GetLastError());

	return S_OK;
}

//	----------------------------------------------------------------------------
static stringwi FormatDate(const SYSTEMTIME& timeSource)
{

	TCHAR lpBuffer[MAX_PATH];
	::GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &timeSource, NULL, lpBuffer, MAX_PATH);

	stringwi strDateTime = lpBuffer;
	::GetTimeFormat(LOCALE_USER_DEFAULT, NULL,  &timeSource, NULL, lpBuffer, MAX_PATH);
	strDateTime.append(L" ");
	strDateTime.append(lpBuffer);

	return strDateTime;
}


//------------------------------------------------------------------------------
_IS_END

#endif //_OBJ_HELPER_H