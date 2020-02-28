// ISExceptionInfo.h: interface for the CISExceptionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISEXCEPTIONINFO_H__06787EC6_095A_11D6_853D_00B0D0235ABE__INCLUDED_)
#define AFX_ISEXCEPTIONINFO_H__06787EC6_095A_11D6_853D_00B0D0235ABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"

////////////////////////////////////////////////////////////////////////////////////
#include "tchar.h"
#include "..\src\ExceptionHandler\ExceptionHandler.h"
#include "..\src\ExceptionHandler\ExceptionResource.h"
#include "appreglocations.h"
////////////////////////////////////////////////////////////////////////////////////

#ifdef ISEXPRESS
const TCHAR* const ISEXCEPTION_PRODUCT			= _T("Express Exceptions");
#else
const TCHAR* const ISEXCEPTION_PRODUCT			= _T("Developer Exceptions");
#endif
const TCHAR* const ISEXCEPTION_EMAIL			= _T("exception@installshield.com");
const TCHAR* const ISEXCEPTION_ATTACHMENT		= _T("");
const TCHAR* const ISEXCEPTION_PRODUCT_REGNAME	= _T("Product"); 
const TCHAR* const ISEXCEPTION_EMAIL_REGNAME	= _T("Email");
const TCHAR* const ISEXCEPTION_ATTACH_REGNAME	= _T("Attachment"); 
const TCHAR* const ISEXCEPTION_LOCALE_REGNAME	= _T("Locale");
const TCHAR* const ISEXCEPTION_RETURN_REGNAME	= _T("Return");
const TCHAR* const ISEXCEPTION_UI_REGNAME		= _T("UI");

class CISExceptionInfo  
{
public:
	CISExceptionInfo(int nResID, DLGPROC DlgProc, HINSTANCE hInstance, HWND hWnd, bool bReadFromRegistry = false);
	virtual ~CISExceptionInfo();
	
	void SetHWND(HWND hWnd);
	void SetResourceID(int nResID);
	void SetProduct(LPCTSTR lpszProduct = 0);

private:
	void SetErrorHandler();
	void GetParameters();

	int       m_nResID;
	HINSTANCE m_hInstance;
	HWND      m_hWnd;
	DWORD     m_dwLocale;
	DWORD     m_dwReturn;
	DWORD     m_dwUI;
	DLGPROC   m_DlgProc;
	TCHAR     m_lpszProduct[MAX_PATH];
	TCHAR     m_lpszEmail[MAX_PATH];
	TCHAR     m_lpszAttachment[MAX_PATH];
};

#endif // !defined(AFX_ISEXCEPTIONINFO_H__06787EC6_095A_11D6_853D_00B0D0235ABE__INCLUDED_)
