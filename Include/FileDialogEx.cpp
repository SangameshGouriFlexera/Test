////////////////////////////////////////////////////////////////
// MSDN -- August 2000
// If this code works, it was written by Paul DiLascia.
// If not, I don't know who wrote it.
// Largely based on original implementation by Michael Lemley.
// Compiles with Visual C++ 6.0, runs on Windows 98 and probably NT too.
//
// CFileDialogEx implements a CFileDialog that uses the new Windows
// 2000 style open/save dialog. Use companion class CDocManagerEx in an
// MFC framework app.
//
#include "stdafx.h"
#include <afxpriv.h>
#include "FileDialogEx.h"
#include "AdminStudio_RegLocations.h"
#include <CommDlg.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef FNERR_BUFFERTOOSMALL
	#define FNERR_BUFFERTOOSMALL	0x3003
#endif

static BOOL IsWin2000();

IMPLEMENT_DYNAMIC(CFileDialogEx, CFileDialog)

CFileDialogEx::CFileDialogEx(BOOL bOpenFileDialog, LPCTSTR lpszDefExt,
	LPCTSTR lpszFileName, DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd,        
    LPCTSTR lpszTitle, LPCTSTR lpszInitialDir) :
	CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName,
		dwFlags, lpszFilter, pParentWnd)
{    
    m_strTitleText = lpszTitle;
    m_strInitialDir = lpszInitialDir;
}


BEGIN_MESSAGE_MAP(CFileDialogEx, CFileDialog)
	//{{AFX_MSG_MAP(CFileDialogEx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL IsWin2000() 
{
   OSVERSIONINFOEX osvi;
   BOOL bOsVersionInfoEx = FALSE;

   // Try calling GetVersionEx using the OSVERSIONINFOEX structure,
   // which is supported on Windows 2000.
   //
   // If that fails, try using the OSVERSIONINFO structure.

   ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

   if( !(bOsVersionInfoEx == GetVersionEx ((OSVERSIONINFO *) &osvi)) )
   {
      // If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.

      osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
      if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
         return FALSE;
   }

   switch (osvi.dwPlatformId)
   {
      case VER_PLATFORM_WIN32_NT:

         if ( osvi.dwMajorVersion >= 5 )
            return TRUE;

         break;
   }
   return FALSE; 
}

//////////////////
// DoModal override copied mostly from MFC, with modification to use
// m_ofnEx instead of m_ofn.
//
int CFileDialogEx::DoModal( )
{
	ASSERT_VALID(this);
	ASSERT(m_ofn.Flags & OFN_ENABLEHOOK);
	ASSERT(m_ofn.lpfnHook != NULL); // can still be a user hook

	int nMaxFiles = (m_ofn.Flags & OFN_ALLOWMULTISELECT)==OFN_ALLOWMULTISELECT?20:1;
	m_ofn.nMaxFile  = (_MAX_PATH * nMaxFiles);
	m_ofn.lpstrFile = m_sOurFileNameBuffer.GetBuffer(m_ofn.nMaxFile+1);
	ZeroMemory(m_ofn.lpstrFile, m_ofn.nMaxFile+1);

	// WINBUG: This is a special case for the file open/save dialog,
	//  which sometimes pumps while it is coming up but before it has
	//  disabled the main window.
	HWND hWndFocus = ::GetFocus();
	BOOL bEnableParent = FALSE;
	m_ofn.hwndOwner = PreModal();
	AfxUnhookWindowCreate();
	if (m_ofn.hwndOwner != NULL && ::IsWindowEnabled(m_ofn.hwndOwner))
	{
		bEnableParent = TRUE;
		::EnableWindow(m_ofn.hwndOwner, FALSE);
	}

	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	ASSERT(pThreadState->m_pAlternateWndInit == NULL);

	if (m_ofn.Flags & OFN_EXPLORER)
		pThreadState->m_pAlternateWndInit = this;
	else
		AfxHookWindowCreate(this);

    if (!m_strTitleText.IsEmpty())
        m_ofn.lpstrTitle = m_strTitleText;

    CRegKey regKey;
    if (!m_strInitialDir.IsEmpty())
        m_ofn.lpstrInitialDir = m_strInitialDir;
    else
    {
        //if lpstrFile is a path, then we ignore any initial directory values
        bool bSlash = false;
        LPTSTR   lpPtr = m_ofn.lpstrFile;
        while (*lpPtr != 0)
        {
               if (*lpPtr == '\\') bSlash = true;  //a \ suggests a path
               lpPtr = CharNext(lpPtr);
        }

        if (!bSlash)
        {
            long lReturn = regKey.Open(HKEY_CURRENT_USER, AdmRegLocations::g_lpszHKCUMainSettingsKey, KEY_READ);
            if (ERROR_SUCCESS == lReturn)
            {
                DWORD lSize = 255;
                lReturn = regKey.QueryValue(m_strInitialDir.GetBuffer(255), AdmRegLocations::g_lpszLastDirectory, &lSize);
                m_strInitialDir.ReleaseBuffer();
                if (ERROR_SUCCESS == lReturn)
                    m_ofn.lpstrInitialDir = m_strInitialDir;
                regKey.Close();
            }
        }
    }

	memset(&m_ofnEx, 0, sizeof(m_ofnEx));
	memcpy(&m_ofnEx, &m_ofn, sizeof(m_ofn));

	m_ofnEx.Flags |= OFN_ENABLESIZING;

#if _MFC_VER < 0x700
	if (IsWin2000())
		m_ofnEx.lStructSize = sizeof(OPENFILENAMEEX);
	else
#endif
		m_ofnEx.lStructSize = sizeof(OPENFILENAME);

	int nResult;
	if (m_bOpenFileDialog)
	{
		nResult = ::GetOpenFileName((OPENFILENAME*)&m_ofnEx);
		if( nResult && ::CommDlgExtendedError() == FNERR_BUFFERTOOSMALL )
		{
			AfxMessageBox(_T("More file where selected than the system can handle at one time.\nPlease select fewer files."), MB_OK | MB_ICONERROR, 0);
			nResult = FALSE;
		}
	}
	else
	{
		nResult = ::GetSaveFileName((OPENFILENAME*)&m_ofnEx);
	}

	m_sOurFileNameBuffer.ReleaseBuffer();

	memcpy(&m_ofn, &m_ofnEx, sizeof(m_ofn));
    m_ofn.lStructSize = sizeof(m_ofn);

	if (nResult){ ASSERT(pThreadState->m_pAlternateWndInit == NULL); }

	pThreadState->m_pAlternateWndInit = NULL;

    //Persist the selected directory as the initial directory if the user presses OK
    if (nResult)
    {
        long lReturn = regKey.Open(HKEY_CURRENT_USER, AdmRegLocations::g_lpszHKCUMainSettingsKey, KEY_WRITE);
        if (ERROR_SUCCESS == lReturn)
        {
            m_strInitialDir = m_ofn.lpstrFile;
            if (m_strInitialDir.GetLength() > (m_ofn.nFileOffset-1))
                m_strInitialDir.SetAt(m_ofn.nFileOffset-1,0);

            regKey.SetValue(m_strInitialDir, AdmRegLocations::g_lpszLastDirectory);
            regKey.Close();
        }
    }

	// WINBUG: Second part of special case for file open/save dialog.
	if (bEnableParent)
		::EnableWindow(m_ofnEx.hwndOwner, TRUE);
	if (::IsWindow(hWndFocus))
		::SetFocus(hWndFocus);

	PostModal();
	return nResult ? nResult : IDCANCEL;
}

//////////////////
// When the open dialog sends a notification, copy m_ofnEx to m_ofn in
// case handler function is expecting updated information in the
// OPENFILENAME struct.
//
BOOL CFileDialogEx::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	memcpy(&m_ofn, &m_ofnEx, sizeof(m_ofn));
   m_ofn.lStructSize = sizeof(m_ofn);

   return CFileDialog::OnNotify( wParam, lParam, pResult);
}

////////////////////////////////////////////////////////////////
// The following functions are provided for testing purposes, to
// demonstrate that they in fact called; ie, that MFC's internal dialog
// proc is hooked up properly. Delete them if you like.
//

BOOL CFileDialogEx::OnFileNameOK()
{
	TRACE(_T("CFileDialogEx::OnFileNameOK\n"));
   return CFileDialog::OnFileNameOK();
}

void CFileDialogEx::OnInitDone()
{
	TRACE(_T("CFileDialogEx::OnInitDone\n"));
   CFileDialog::OnInitDone();
}

void CFileDialogEx::OnFileNameChange()
{
	TRACE(_T("CFileDialogEx::OnFileNameChange\n"));
   CFileDialog::OnFileNameChange();
}

void CFileDialogEx::OnFolderChange()
{
	TRACE(_T("CFileDialogEx::OnFolderChange\n"));
   CFileDialog::OnFolderChange();
}

void CFileDialogEx::OnTypeChange()
{
	TRACE(_T("OnTypeChange(), index = %d\n"), m_ofn.nFilterIndex);
   CFileDialog::OnTypeChange();
}


