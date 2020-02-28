#if !defined(AFX_GENWORKSPACEMANAGER_H__4859ABFB_14A7_428E_ACDF_65FDB86B95AC__INCLUDED_)
#define AFX_GENWORKSPACEMANAGER_H__4859ABFB_14A7_428E_ACDF_65FDB86B95AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

#include "ISOleControlSite.h"

/////////////////////////////////////////////////////////////////////////////
// CGenWorkspaceManager wrapper class
class AFX_EXT_CLASS CGenWorkspaceManager : public CWnd
{
protected:
	DECLARE_DYNCREATE(CGenWorkspaceManager)
public:
	CLSID const& GetClsid()
	{
		#ifndef __ISWACK
			static CLSID const clsid
				= { 0x72a03438, 0x410c, 0x48ca, { 0xa3, 0x48, 0x5f, 0x43, 0xab, 0xb, 0x64, 0xf0 } };
		#elif ITWI_OEMVERSION
			static CLSID const clsid
				= { 0x9992241E, 0x6EF3, 0x4636, { 0xB8, 0xB2, 0x21, 0x35, 0xC8, 0xBA, 0x73, 0xE7 } };
		#else
			static CLSID const clsid 
				= {  0x1FDAAE77, 0x810C, 0x11D5, { 0xAB, 0x7C, 0x00, 0xC0, 0x4F, 0x09, 0x71, 0x9A }  };
		#endif

		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateEx(lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateEx(lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey); }

	BOOL CreateEx(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{
		CRect rect2( rect );
		CPoint pt;
		CSize size;

		pt = rect2.TopLeft();
		size = rect2.Size();

		CISWnd* pISParentWnd = (CISWnd*) pParentWnd;

		if ((pParentWnd == NULL) || !pISParentWnd->InitControlContainerEx())
			return FALSE;
		
		CISOleControlContainer* pISOleCtrlCont = pISParentWnd->GetCtrlCont();

		return pISOleCtrlCont->CreateControlEx(this, _T("ISWrkSpaceMgr.dll"), GetClsid(), lpszWindowName, dwStyle, &pt, &size, nID, 
			pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:

// Operations
public:
	void Initialize(LPUNKNOWN pUIServices);
	void ShowWorkspace(LPCTSTR bstrName);
	void LoadWorkspace(LPCTSTR bstrName);
	void CloseWorkspace(LPCTSTR bstrName);
	void CloseAllWorkspaces();
	CComPtr<IDispatch> GetActiveWorkspace();
	long GetWorkspaceHWND(LPCTSTR bstrName);

	void ShowWorkspaceEx(LPCTSTR bstrName, VARIANT_BOOL bScrollBars);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENWORKSPACEMANAGER_H__4859ABFB_14A7_428E_ACDF_65FDB86B95AC__INCLUDED_)
