// ISOleControlSite.h: interface for the CISOleControlSite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISOLECONTROLSITE_H__C38CA2C3_0489_4C5C_9963_41DBE2DBCA46__INCLUDED_)
#define AFX_ISOLECONTROLSITE_H__C38CA2C3_0489_4C5C_9963_41DBE2DBCA46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <occimpl.h>
#include "IsCoCreateInproc.h"
	
class CISOleControlContainer;
class CISOleControlSite;

class CISWnd : public CWnd
{
public:
	CISOleControlContainer* GetCtrlCont()
	{
		return (CISOleControlContainer*) m_pCtrlCont;
	}
	CISOleControlSite* GetCtrlSite()
	{
		return (CISOleControlSite*) m_pCtrlSite;
	}
	void SetCtrlSite(CISOleControlSite* pCtrlSite)
	{
		m_pCtrlSite = (COleControlSite*) pCtrlSite;
	}
	BOOL InitControlContainerEx()
	{
		return InitControlContainer();
	}
};

class CISOleControlSite : public COleControlSite
{
public:
// Constructors/destructors
	CISOleControlSite(COleControlContainer* pCtrlCont) : COleControlSite(pCtrlCont)
	{
	};
	~CISOleControlSite(){};

	HRESULT CreateControlEx(CWnd* pWndCtrl, LPCTSTR szDLLName, REFCLSID clsid, 
			LPCTSTR lpszWindowName, DWORD dwStyle, const POINT* ppt, const SIZE* psize,
			UINT nID, CFile* pPersist=NULL, BOOL bStorage=FALSE, BSTR bstrLicKey=NULL)
{
	HRESULT hr = E_FAIL;
	m_hWnd = NULL;
    CSize size;

	// Connect the OLE Control with its proxy CWnd object
	if (pWndCtrl != NULL)
	{
		CISWnd* pCISWndCtrl = (CISWnd*) pWndCtrl;
		ASSERT(pCISWndCtrl->GetCtrlSite() == NULL);
		m_pWndCtrl = pWndCtrl;
		pCISWndCtrl->SetCtrlSite(this);
	}

	// Initialize OLE, if necessary
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	if (!pState->m_bNeedTerm && !AfxOleInit())
		return hr;

	if (SUCCEEDED(hr = CreateOrLoadEx(szDLLName, clsid, pPersist, bStorage, bstrLicKey)))
	{
		ASSERT(m_pObject != NULL);
		m_nID = nID;

		if (psize == NULL)
		{
			// If psize is NULL, ask the object how big it wants to be.
			CClientDC dc(NULL);

			m_pObject->GetExtent(DVASPECT_CONTENT, &size);
			dc.HIMETRICtoDP(&size);
			m_rect = CRect(*ppt, size);
		}
		else
		{
			m_rect = CRect(*ppt, *psize);
		}

		m_dwStyleMask = WS_GROUP | WS_TABSTOP;

		if (m_dwMiscStatus & OLEMISC_ACTSLIKEBUTTON)
			m_dwStyleMask |= BS_DEFPUSHBUTTON;

		if (m_dwMiscStatus & OLEMISC_INVISIBLEATRUNTIME)
			dwStyle &= ~WS_VISIBLE;

		m_dwStyle = dwStyle & m_dwStyleMask;

		// If control wasn't quick-activated, then connect sinks now.
		if (hr != S_FALSE)
		{
			m_dwEventSink = ConnectSink(m_iidEvents, &m_xEventSink);
			m_dwPropNotifySink = ConnectSink(IID_IPropertyNotifySink,
				&m_xPropertyNotifySink);
		}
		m_dwNotifyDBEvents = ConnectSink(IID_INotifyDBEvents, &m_xNotifyDBEvents);

		// Now that the object has been created, attempt to
		// in-place activate it.

		SetExtent();

		if (SUCCEEDED(hr = m_pObject->QueryInterface(IID_IOleInPlaceObject,
				(LPVOID*)&m_pInPlaceObject)))
		{
			if (dwStyle & WS_VISIBLE)
			{
				// control is visible: just activate it
				hr = DoVerb(OLEIVERB_INPLACEACTIVATE);
			}
			else
			{
				// control is not visible: activate off-screen, hide, then move
				m_rect.OffsetRect(-32000, -32000);
				if (SUCCEEDED(hr = DoVerb(OLEIVERB_INPLACEACTIVATE)) &&
					SUCCEEDED(hr = DoVerb(OLEIVERB_HIDE)))
				{
					m_rect.OffsetRect(32000, 32000);
					hr = m_pInPlaceObject->SetObjectRects(m_rect, m_rect);
				}
			}
		}
		else
		{
			TRACE1("IOleInPlaceObject not supported on OLE control (dialog ID %d).\n", nID);
			TRACE1(">>> Result code: 0x%08lx\n", hr);
		}

		if (SUCCEEDED(hr))
			GetControlInfo();

		// if QueryInterface or activation failed, cleanup everything
		if (FAILED(hr))
		{
			if (m_pInPlaceObject != NULL)
			{
				m_pInPlaceObject->Release();
				m_pInPlaceObject = NULL;
			}
			DisconnectSink(m_iidEvents, m_dwEventSink);
			DisconnectSink(IID_IPropertyNotifySink, m_dwPropNotifySink);
			DisconnectSink(IID_INotifyDBEvents, m_dwNotifyDBEvents);
			m_dwEventSink = 0;
			m_dwPropNotifySink = 0;
			m_dwNotifyDBEvents = 0;
			m_pObject->Release();
			m_pObject = NULL;
		}
	}

	if (SUCCEEDED(hr))
	{
		AttachWindow();

		ASSERT(m_hWnd != NULL);

		// Initialize the control's Caption or Text property, if any
		if (lpszWindowName != NULL)
			SetWindowText(lpszWindowName);

		// Initialize styles
		ModifyStyle(0, m_dwStyle | (dwStyle & (WS_DISABLED|WS_BORDER)), 0);
	}

	return hr;
}



	HRESULT CreateOrLoadEx(LPCTSTR szDLLName, REFCLSID clsid, CFile* pFile,
	BOOL bStorage, BSTR bstrLicKey)
{
	ASSERT(m_pObject == NULL);

#ifdef _DEBUG
	OLECHAR wszClsid[40];
	StringFromGUID2(clsid, wszClsid, 40);
#endif //_DEBUG

	HRESULT hr;
	CComPtr<IUnknown> spUnknown;
	if (FAILED(hr = ISCoCreateInstance(szDLLName, clsid, &spUnknown)))
	{
		TRACE1("CoCreateInstance of OLE control %ls failed.\n", wszClsid);
		TRACE1(">>> Result code: 0x%08lx\n", hr);
		TRACE0(">>> Is the control is properly registered?\n");
		return hr;
	}
	
	spUnknown.QueryInterface(&m_pObject);
	

	LPPERSISTSTREAMINIT pPersStm = NULL;
	LPPERSISTSTORAGE pPersStg = NULL;
	LPPERSISTMEMORY pPersMem = NULL;

	GetEventIID(&m_iidEvents);
	// Try to quick-activate first
	BOOL bQuickActivated = QuickActivate();

	if (!bQuickActivated)
	{
		m_pObject->GetMiscStatus(DVASPECT_CONTENT, &m_dwMiscStatus);

		// set client site first, if appropriate
		if (m_dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST)
		{
			if (FAILED(hr = m_pObject->SetClientSite(&m_xOleClientSite)))
			{
				TRACE1("SetClientSite on OLE control %ls failed.\n", wszClsid);
				TRACE1(">>> Result code: 0x%08lx\n", hr);
				goto CreateOrLoadFailed;
			}
		}
	}

	ASSERT(!bStorage || pFile != NULL);

	// initialize via IPersistMemory (direct buffering)
	if (pFile != NULL && !bStorage &&
		SUCCEEDED(m_pObject->QueryInterface(IID_IPersistMemory, (void**)&pPersMem)) &&
		pFile->GetBufferPtr(CFile::bufferCheck) != 0)
	{
		ASSERT(pPersMem != NULL);

		// file supports direct buffering, get its buffer pointer and size
		LPVOID pvBuffer = NULL;
		LPVOID pvEnd;
		ULONG cbBuffer = pFile->GetBufferPtr(
			CFile::bufferRead, (UINT)-1, &pvBuffer, &pvEnd);
		ASSERT(((LPBYTE)pvEnd - (LPBYTE)pvBuffer) == (int)cbBuffer);

		// and then load it directly
		hr = pPersMem->Load(pvBuffer, cbBuffer);
		pPersMem->Release();
		pPersMem = NULL;
		if (FAILED(hr))
			goto CreateOrLoadFailed;
	}
	// initialize via IPersistStreamInit
	else if (!bStorage && SUCCEEDED(m_pObject->QueryInterface(
		IID_IPersistStreamInit, (void**)&pPersStm)))
	{
		ASSERT(pPersStm != NULL);

		if (pFile == NULL)
		{
			// just call InitNew
			hr = pPersStm->InitNew();
		}
		else
		{
			// open an IStream on the data and pass it to Load
#ifdef DEBUG
			::MessageBox(NULL, _T("Need to fix CreateOrLoad in ISOleControlsite.h"), _T("InstallShield -- DEBUG ONLY"),MB_OK);
#endif
			CArchive ar(pFile, CArchive::load);
			//CArchiveStream stm(&ar);
			//hr = pPersStm->Load(&stm);
		}
		pPersStm->Release();

		if (FAILED(hr))
		{
			TRACE1("InitNew or Load on OLE control %ls failed.\n", wszClsid);
			TRACE1(">>> Result code: 0x%08lx\n", hr);
			goto CreateOrLoadFailed;
		}
	}
	// initialize via IPersistStorage
	else if (SUCCEEDED(m_pObject->QueryInterface(
		IID_IPersistStorage, (void**)&pPersStg)))
	{
		ASSERT(pPersStg != NULL);

		if (pFile == NULL)
		{
			// create a scratch IStorage and pass it to InitNew
			LPLOCKBYTES pLockBytes = NULL;
			if (SUCCEEDED(hr = CreateILockBytesOnHGlobal(NULL, TRUE,
				&pLockBytes)))
			{
				ASSERT(pLockBytes != NULL);
				LPSTORAGE pStorage = NULL;
				if (SUCCEEDED(hr = StgCreateDocfileOnILockBytes(pLockBytes,
					STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0,
					&pStorage)))
				{
					ASSERT(pStorage != NULL);
					hr = pPersStg->InitNew(pStorage);
					pStorage->Release();
				}
				pLockBytes->Release();
			}
		}
		else if (bStorage)
		{
			// copy data to an HGLOBAL, so we can build an IStorage on it
			UINT cb = pFile->GetLength();
			HGLOBAL hGlobal;
			BYTE* pbData;

			if (((hGlobal = GlobalAlloc(GMEM_FIXED, cb)) != NULL) &&
				((pbData = (BYTE*)GlobalLock(hGlobal)) != NULL))
			{
				pFile->Read(pbData, cb);
				GlobalUnlock(hGlobal);
			}
			else
			{
				hr = E_OUTOFMEMORY;
				hGlobal = NULL;
			}

			// open an IStorage on the data and pass it to Load
			LPLOCKBYTES pLockBytes = NULL;
			if ((hGlobal != NULL) &&
				SUCCEEDED(hr = CreateILockBytesOnHGlobal(hGlobal, TRUE,
				&pLockBytes)))
			{
				ASSERT(pLockBytes != NULL);
				LPSTORAGE pStorage = NULL;
				if (SUCCEEDED(hr = StgOpenStorageOnILockBytes(pLockBytes, NULL,
					STGM_READWRITE | STGM_SHARE_EXCLUSIVE, NULL, 0, &pStorage)))
				{
					ASSERT(pStorage != NULL);
					hr = pPersStg->Load(pStorage);
					pStorage->Release();
				}
				pLockBytes->Release();
			}
		}
		else
		{
			hr = E_UNEXPECTED;
		}
		pPersStg->Release();

		if (FAILED(hr))
		{
			TRACE1("InitNew or Load on OLE control %ls failed.\n", wszClsid);
			TRACE1(">>> Result code: 0x%08lx\n", hr);
			goto CreateOrLoadFailed;
		}
	}
	else
	{
		TRACE1("Persistence not supported on OLE control %ls.\n", wszClsid);
		TRACE1(">>> Result code: 0x%08lx\n", hr);
		goto CreateOrLoadFailed;
	}

	if (!bQuickActivated)
	{
		// set client site last, if appropriate
		if (!(m_dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST))
		{
			if (FAILED(hr = m_pObject->SetClientSite(&m_xOleClientSite)))
			{
				TRACE1("SetClientSite on OLE control %ls failed.\n", wszClsid);
				TRACE1(">>> Result code: 0x%08lx\n", hr);
				goto CreateOrLoadFailed;
			}
		}
	}

CreateOrLoadFailed:
	if (FAILED(hr) && (m_pObject != NULL))
	{
		m_pObject->Close(OLECLOSE_NOSAVE);
		m_pObject->Release();
		m_pObject = NULL;
	}

	if (pPersMem != NULL)
		pPersMem->Release();

	if (bQuickActivated && SUCCEEDED(hr))
		hr = S_FALSE;

	return hr;
}
};

class CISOleControlContainer: public COleControlContainer
{
public:
	CISOleControlContainer(CWnd*  pWnd) : COleControlContainer(pWnd)
	{};
	virtual ~CISOleControlContainer(){};
	BOOL CreateControlEx(CWnd* pWndCtrl, LPCTSTR szDLLName, REFCLSID clsid,
		LPCTSTR lpszWindowName, DWORD dwStyle, const POINT* ppt, const SIZE* psize,
		UINT nID, CFile* pPersist=NULL, BOOL bStorage=FALSE, BSTR bstrLicKey=NULL,
		COleControlSite** ppNewSite=NULL)
{
	CISOleControlSite* pSite = NULL;

	TRY
	{
		pSite = (CISOleControlSite*) afxOccManager->CreateSite(this);
	}
	END_TRY

	if (pSite == NULL)
		return FALSE;

	BOOL bCreated = SUCCEEDED( pSite->CreateControlEx(pWndCtrl, szDLLName, clsid,
		lpszWindowName, dwStyle, ppt, psize, nID, pPersist, bStorage,
	  bstrLicKey ) );

	if (bCreated)
	{
		ASSERT(pSite->m_hWnd != NULL);
		m_siteMap.SetAt(pSite->m_hWnd, pSite);
		if (ppNewSite != NULL)
			*ppNewSite = pSite;
	}
	else
	{
		delete pSite;
	}

	return bCreated;
}
};

#endif // !defined(AFX_ISOLECONTROLSITE_H__C38CA2C3_0489_4C5C_9963_41DBE2DBCA46__INCLUDED_)
