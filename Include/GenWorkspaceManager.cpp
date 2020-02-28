// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "genworkspacemanager.h"

/////////////////////////////////////////////////////////////////////////////
// CGenWorkspaceManager

IMPLEMENT_DYNCREATE(CGenWorkspaceManager, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CGenWorkspaceManager properties

/////////////////////////////////////////////////////////////////////////////
// CGenWorkspaceManager operations

void CGenWorkspaceManager::Initialize(LPUNKNOWN pUIServices)
{
	static BYTE parms[] =
		VTS_UNKNOWN;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pUIServices);
}

void CGenWorkspaceManager::ShowWorkspace(LPCTSTR bstrName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 bstrName);
}

void CGenWorkspaceManager::LoadWorkspace(LPCTSTR bstrName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 bstrName);
}

void CGenWorkspaceManager::CloseWorkspace(LPCTSTR bstrName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 bstrName);
}

void CGenWorkspaceManager::CloseAllWorkspaces()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CComPtr<IDispatch> CGenWorkspaceManager::GetActiveWorkspace()
{
	CComPtr<IDispatch> result;
	InvokeHelper(0x60020004, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long CGenWorkspaceManager::GetWorkspaceHWND(LPCTSTR bstrName)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		bstrName);
	return result;
}

void CGenWorkspaceManager::ShowWorkspaceEx(LPCTSTR bstrName, VARIANT_BOOL bScrollBars)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BOOL;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrName, bScrollBars);
}