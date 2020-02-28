// ISExceptionInfo.cpp: implementation of the CISExceptionInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ISExceptionInfo.h"
#include "..\src\isappservices\isappservices.h"
#include "iscocreateinproc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CISExceptionInfo::CISExceptionInfo(int nResID, DLGPROC DlgProc, HINSTANCE hInstance, HWND hWnd, bool bReadFromRegistry)
	:m_nResID(nResID),
	 m_DlgProc(DlgProc),
	 m_hInstance(hInstance),
	 m_hWnd(hWnd),
	 m_dwLocale(::GetSystemDefaultLCID()),
	 m_dwReturn(EXCEPTION_EXECUTE_ONCE),
	 m_dwUI(EXCEPTION_HANDLER_UI_FULL)
{
	lstrcpy(m_lpszProduct, ISEXCEPTION_PRODUCT);
	lstrcpy(m_lpszEmail, ISEXCEPTION_EMAIL);
	lstrcpy(m_lpszAttachment, ISEXCEPTION_ATTACHMENT);

	if (bReadFromRegistry)
	{	
		GetParameters();
	}

	SetErrorHandler();
}

CISExceptionInfo::~CISExceptionInfo()
{

}

void CISExceptionInfo::SetErrorHandler()
{	
	//Call function to initialize error handling	
	SetExceptionHandler(
		m_nResID,                         //Resource ID
		m_DlgProc,                        //DLGPROC
		m_hInstance,                      //hInstance
		m_hWnd,                           //hWnd
		m_lpszProduct,                    //lpszProduct 
		m_lpszEmail,                      //lpszEmail 
		m_lpszAttachment,                 //lpszAttachment
		m_dwLocale,                       //locale
		_T(""),                           //command line
		m_dwReturn,                       //return
		m_dwUI                            //UI type
		);
}

void CISExceptionInfo::GetParameters()
{
	CComPtr<ILocalSettingsProteus> spLocalSettings;
	ISCoCreateInstance(ISAPPSERVICES_DLL, __uuidof(AppSettings), &spLocalSettings);
	
	stringx strRegRoot;
	spLocalSettings->get_RegistryRoot(&strRegRoot);
	strRegRoot.path_append(ISEXCEPTION_REGKEY_TOKEN);

	HKEY hkResult;
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strRegRoot, 0, KEY_READ, &hkResult))
	{
		TCHAR szData[MAX_PATH] = {0};
		DWORD dwDataSize = sizeof(szData)/sizeof(TCHAR) - 1;
		DWORD dwData = 0;
		DWORD dwType = 0;

		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_PRODUCT_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(szData), &dwDataSize) && (REG_SZ == dwType))
		{
			lstrcpy(m_lpszProduct, szData);
		}
		
		::ZeroMemory(szData, sizeof(szData)/sizeof(TCHAR));
		dwDataSize = sizeof(szData)/sizeof(TCHAR) - 1;
		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_EMAIL_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(szData), &dwDataSize) && (REG_SZ == dwType))
		{
			lstrcpy(m_lpszEmail, szData);
		}

		::ZeroMemory(szData, sizeof(szData)/sizeof(TCHAR));
		dwDataSize = sizeof(szData)/sizeof(TCHAR) - 1;
		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_ATTACH_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(szData), &dwDataSize) && (REG_SZ == dwType))
		{
			lstrcpy(m_lpszAttachment, szData);
		}

		dwDataSize = sizeof(dwData);
		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_LOCALE_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(&dwData), &dwDataSize) && (REG_DWORD == dwType))
		{
			m_dwLocale = dwData;
		}

		dwDataSize = sizeof(dwData);
		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_RETURN_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(&dwData), &dwDataSize) && (REG_DWORD == dwType))
		{
			m_dwReturn = dwData;
		}

		dwDataSize = sizeof(dwData);
		if (ERROR_SUCCESS == ::RegQueryValueEx(hkResult, ISEXCEPTION_UI_REGNAME, 0, &dwType, reinterpret_cast<LPBYTE>(&dwData), &dwDataSize) && (REG_DWORD == dwType))
		{
			m_dwUI = dwData;
		}
		::RegCloseKey(hkResult);
	}
}

void CISExceptionInfo::SetHWND(HWND hWnd)
{
	m_hWnd = hWnd;
	SetErrorHandler();
}

void CISExceptionInfo::SetResourceID(int nResID)
{
	m_nResID = nResID;
	SetErrorHandler();
}

void CISExceptionInfo::SetProduct(LPCTSTR lpszProduct)
{
	if (lpszProduct)
	{
		lstrcpy(m_lpszProduct, lpszProduct);
	}
	SetErrorHandler();
}