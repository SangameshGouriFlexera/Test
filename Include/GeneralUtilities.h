#if !defined(GENERAL_UTILITIES_CS_INCLUDED_)
#define GENERAL_UTILITIES_CS_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment(lib, "mpr.lib")

#include <atlbase.h>
#include "stringx.h"

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

static BOOL CS_IsWow64()
{
	LPFN_ISWOW64PROCESS fnIsWow64Process;
    BOOL bIsWow64 = FALSE;

    fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");
  
    if (NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {
            // handle error
        }
    }
    return bIsWow64;
}

//This function does what you would expect. 
static BOOL CS_DetermineComputerName(CString& strSystemName)
{

  DWORD dwSize = MAX_PATH;
  BOOL bResults = GetComputerName(strSystemName.GetBuffer(MAX_PATH), &dwSize);
  strSystemName.ReleaseBuffer();

  if (!bResults)
      strSystemName.Empty();

  return bResults;
}

static CComBSTR CS_GetUnicodePath(LPCTSTR lpstrPath)
{
	CString strPath;
	strPath = _T("\\\\?\\");
	if(_tcslen(lpstrPath)>=3 && lpstrPath[0]=='\\' && lpstrPath[1]=='\\')
	{
		CString sUnc(lpstrPath);
		sUnc.Replace(_T("\\\\"),_T("UNC\\"));
		strPath += sUnc;
	}
	else
	{
		strPath += lpstrPath;
	}

	return CComBSTR(strPath);
}

//This function does what you would expect.  For now, we
//will use GetFileAttributes for this functionality.
static bool CS_FileExist(LPCTSTR lpstrFilePath)
{
	return (0xFFFFFFFF == GetFileAttributesW(CS_GetUnicodePath(lpstrFilePath)))?false:true;
}

static bool CS_CreateDirectory(LPCTSTR lpstrDirectory)
{
	return (CreateDirectoryW(CS_GetUnicodePath(lpstrDirectory),NULL)!=0)?true:false;
}

static bool CS_CopyFile(LPCTSTR lpstrSource,LPCTSTR lpstrDestination)
{
	return (CopyFileW(CS_GetUnicodePath(lpstrSource),CS_GetUnicodePath(lpstrDestination),FALSE)!=0)?true:false;
}

static bool CS_MoveFile(LPCTSTR lpstrSource,LPCTSTR lpstrDestination)
{
	return (MoveFileW(CS_GetUnicodePath(lpstrSource),CS_GetUnicodePath(lpstrDestination))!=0)?true:false;
}

//This function does what you would expect.  For now, we
//will use GetFileAttributes for this functionality.  
static bool CS_DeleteDirectory(LPCTSTR lpstrDirectory, LPCTSTR lpstrBaseDirectory)
{
    //paranoid check, leave in as is...
    CString strDirectory = lpstrDirectory;
    if (strDirectory.Find(lpstrBaseDirectory) != 0)
        return false;

    try
    {
        TCHAR  szDir[MAX_PATH];
        _tcscpy(szDir, lpstrDirectory);
        if (szDir[_tcslen(szDir)-1] != '\\')
            _tcscat(szDir, _T("\\"));
        _tcscat(szDir, _T("*.*"));

        WIN32_FIND_DATA FindFileData;	
	    HANDLE hSearch = FindFirstFile(szDir, &FindFileData);
	    if (hSearch == INVALID_HANDLE_VALUE)
		    return false;

        do
	    {			
            TCHAR  szLocalDir[MAX_PATH];
            _tcscpy(szLocalDir, lpstrDirectory);
            if (szLocalDir[_tcslen(szLocalDir)-1] != '\\')
                _tcscat(szLocalDir, _T("\\"));
            _tcscat(szLocalDir, FindFileData.cFileName);

            if (0 == (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		    {
                ::SetFileAttributes(szLocalDir, FILE_ATTRIBUTE_NORMAL);
                ::DeleteFile(szLocalDir);
		    }
              else
            {
                if (_tcsicmp(FindFileData.cFileName, _T("..")) != 0 &&
                    _tcsicmp(FindFileData.cFileName, _T(".")) != 0)
                    CS_DeleteDirectory(szLocalDir, lpstrBaseDirectory);
            }
	    }
	    while (FindNextFile(hSearch,&FindFileData));

	    FindClose(hSearch);

	    RemoveDirectory(lpstrDirectory);
    }
     catch (...)
    {
        return false;
    }

	return true;
}

//This function does what you would expect.  For now, we
//will not recurse directory hierarchies, no trailing '\' expected
static bool CS_DeleteDirectory(LPCTSTR lpstrDirectory)
{
	if (!CS_FileExist(lpstrDirectory))  //works for directories
		 return false;

    TCHAR szFile[MAX_PATH];    
	_tcscpy(szFile, lpstrDirectory);
	_tcscat(szFile, _T("\\*.*"));

    WIN32_FIND_DATA FindFileData;	
	HANDLE hSearch = FindFirstFile(szFile,&FindFileData);
	if (hSearch == INVALID_HANDLE_VALUE)
		return false;
    do
	{   if (0 == (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		//if (!(FindFileData.dwFileAttributes&(FILE_ATTRIBUTE_DIRECTORY|FILE_ATTRIBUTE_SYSTEM)))
		{
			TCHAR szLocalFile[MAX_PATH];			
			_tcscpy(szLocalFile, lpstrDirectory);
			_tcscat(szLocalFile, _T("\\"));
			_tcscat(szLocalFile, FindFileData.cFileName);
			DeleteFile(szLocalFile);
		}
	}
	while (FindNextFile(hSearch,&FindFileData));
	FindClose(hSearch);

	RemoveDirectory(lpstrDirectory);

	return true;
}

//This function converts that current system time or the provided system time
//into a string suitable for insertion in a SQL Query or just for display.
static bool CS_ConvertDate(const PSYSTEMTIME pST, LPTSTR lpstrDate)
{
    TCHAR   szDate[255], szTime[255];
    szDate[0] = 0; szTime[0] = 0;

	SYSTEMTIME  st;
	PSYSTEMTIME pSTLocal = &st;
	if (pST) pSTLocal = pST;
	   else GetSystemTime(&st);

    if (!GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, pSTLocal, NULL, szDate, 255))
		return false;

    if (!GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE|TIME_FORCE24HOURFORMAT|TIME_NOTIMEMARKER, pSTLocal, NULL, szTime, 255))
		return false;
	
	wsprintf(lpstrDate, _T("%s %s"), szDate, szTime);
	return true;
}

//This function returns the localized day name using day of week information found in the SYSTEMTIME structure
static CString CS_GetDayName(int iDayId, CString &strDefault)
{
    CString strOutput;
    strOutput = strDefault;
    TCHAR   szDayName[255] = {0};

    switch (iDayId)
    {
    case 0:     //Sunday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME7, szDayName, 255);
        break;
    case 1:     //Monday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME1, szDayName, 255);
        break;
    case 2:     //Tuesday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME2, szDayName, 255);
        break;
    case 3:     //Wednesday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME3, szDayName, 255);
        break;
    case 4:     //Thrusday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME4, szDayName, 255);
        break;
    case 5:     //Friday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME5, szDayName, 255);
        break;
    case 6:     //Saturday
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDAYNAME6, szDayName, 255);
        break;
    }

    if (szDayName[0] != 0)
        strOutput = szDayName;

    return strOutput;
}

//This function converts that dtDate to a correct display-able data for
//the given system.  Converting from GMT if so specified.
static bool CS_ConvertDate(DATE dtDate, LPTSTR lpstrDate, bool bLocalTime, bool bIncludeTime = true, DWORD dwDateFormat = DATE_LONGDATE)
{
    *lpstrDate = 0;

    SYSTEMTIME st;
    VariantTimeToSystemTime(dtDate, &st);

    if (bLocalTime)
    {
        FILETIME ft, ftLocal;
        SystemTimeToFileTime(&st, &ft);
        FileTimeToLocalFileTime(&ft, &ftLocal);
        FileTimeToSystemTime(&ftLocal, &st);
    }

    TCHAR   szDate[255], szTime[255];
    szDate[0] = 0; szTime[0] = 0;
    GetDateFormat(LOCALE_USER_DEFAULT, dwDateFormat, &st, NULL, szDate, 255);
    GetTimeFormat(LOCALE_USER_DEFAULT, TIME_NOSECONDS|LOCALE_NOUSEROVERRIDE|TIME_FORCE24HOURFORMAT|TIME_NOTIMEMARKER, &st, NULL, szTime, 255);

    _tcscpy(lpstrDate, szDate);
    if (_tcslen(szTime) > 0 && bIncludeTime)
    {
		if (dwDateFormat == DATE_SHORTDATE)
            _tcscat(lpstrDate, _T(" "));
		  else
           _tcscat(lpstrDate, _T(" - "));
        _tcscat(lpstrDate, szTime);
    }

    return true;
}


//Utility function to shorten the paths to ensure that they fit in the stated width.
//As constructed, the function depends on tchar defines.
static bool CS_ShortenPath(LPTSTR lpTemp, int iWidth, HANDLE hFont)
{
    TCHAR    szWorking[255];
    _tcscpy(szWorking, lpTemp);

    LPTSTR lpFilePtr  = 0;
    LPTSTR lpDrivePtr = szWorking;
    LPTSTR lpDirPtr   = 0;
    LPTSTR lpItem     = lpDrivePtr;
    long  lCurrentCount, lCount;

    //find the position of the drive
    if (*lpItem == '\\' && *CharNext(lpItem) == '\\') //suggests UNC
        lCount = 4; 
     else
    {   
        if (*CharNext(lpItem) == ':') //suggest drive letter  
            lCount = 1;         
         else
           return false;
    }

    lCurrentCount = 0;
    while (lCount != lCurrentCount && *lpItem != NULL)
    {
            if (*lpItem == '\\') lCurrentCount++;
           lpItem = CharNext(lpItem);
    } 

    lpDirPtr = lpItem;  //set my dir pointer on the slash

    //find last slash for your file pointer
    while (*lpItem != NULL)
    {
           if (*lpItem == '\\')
               lpFilePtr = lpItem;
           lpItem = CharNext(lpItem);
    }

    if (lpFilePtr == NULL || lpDirPtr == NULL)
        return false;

    if (lpFilePtr != lpDirPtr)  //nothing to shorten otherwise
    {
        TCHAR  szFile[255], szDrive[255], szDirectory[255];
        _tcscpy(szFile, lpFilePtr);
        *lpFilePtr = 0;
        _tcscpy(szDirectory, lpDirPtr);
        *lpDirPtr = 0;
        _tcscpy(szDrive, lpDrivePtr);

        HDC hDC = ::GetDC(NULL);
        ::SelectObject(hDC, hFont);

        SIZE  sz;
        GetTextExtentPoint(hDC, lpTemp, _tcslen(lpTemp), &sz);
        if (sz.cx > iWidth)
        {
            szWorking[0] = 0;
            lpDirPtr = szDirectory;
            while (*lpDirPtr != NULL)
            {
                   if (*lpDirPtr == '\\')
                   {    //check the size;
                       _tcscpy(szWorking, szDrive);
                       _tcscat(szWorking, _T("..."));
                       _tcscat(szWorking, lpDirPtr);
                       _tcscat(szWorking, szFile);
                       GetTextExtentPoint(hDC, szWorking, _tcslen(szWorking), &sz);
                       if (sz.cx <= iWidth)
                           break;
                   }
                   lpDirPtr = CharNext(lpDirPtr);
            }
            if (szWorking[0] != 0 && *lpDirPtr != NULL)
                _tcscpy(lpTemp, szWorking);
        }

        ::ReleaseDC(NULL, hDC);
    }

    return true;
}

static bool CS_ShortenPath(CString& text, CWnd& wnd, int iAdjustment = 10)
{

	if (wnd.m_hWnd)
	{
		CRect rc;
		wnd.GetClientRect(&rc);
		rc.right -= iAdjustment;  //the control likely has borders which we don't want to cross
		CFont *pFont = wnd.GetFont();
		int iTextLength = text.GetLength();
		if (pFont->m_hObject && rc.right > 0 && iTextLength > 0)
		{
			LPTSTR lpData = text.GetBuffer(iTextLength+5);
			bool bReturn = CS_ShortenPath(lpData, rc.right, pFont->m_hObject);
			text.ReleaseBuffer();
			return bReturn;
		}
	}

	return false;
}

static void CS_ProcessSingleQuotes(const CString strString, CString &strNewString)
{
    int iCurrentPos = 0;
    int iPos;

	strNewString.Empty();
    iPos = strString.Find(_T("'"), iCurrentPos);
    while (iPos != -1)
    {
        strNewString += strString.Mid(iCurrentPos,iPos-iCurrentPos);
        strNewString += _T("''");
        iCurrentPos = iPos+1;

        iPos = strString.Find(_T("'"), iCurrentPos);
    }
    
    strNewString += strString.Mid(iCurrentPos);
}

//-------------------------------------------------------------------------
//  This function will convert any network mapped drives to their UNC
//  equivalent.  We will store mostly UNC paths within ConflictSolver.
//  We will attempt the convertion but not be to concerned if it fails.
static void CS_ConvertMappedDrivesToUNC(CString &strPath)
{
    TCHAR  szPath[MAX_PATH * 2], szWorkingPath[MAX_PATH * 2];
    _tcscpy(szWorkingPath, strPath);

    LPTSTR  lpItem = szWorkingPath;

    //if UNC path already, then forget about it.
    if (*lpItem == '\\' && *CharNext(lpItem) == '\\') //suggests UNC
        return;

    //Mapped drive in the form C:\, we want the first '\' character
    while (*lpItem != NULL && *lpItem != '\\')
           lpItem = CharNext(lpItem);

    if (*lpItem == NULL)    //strange path, just forget about it.
        return;

    _tcscpy(szPath, lpItem);
    lpItem = CharNext(lpItem);
    *lpItem = 0;

    if (DRIVE_REMOTE == GetDriveType(szWorkingPath))
    {
        TCHAR  szRemoteName[MAX_PATH * 2];
        unsigned long   ulLength = MAX_PATH * 2;
        lpItem = CharPrev(szWorkingPath, lpItem);
        *lpItem = 0;
        if (NO_ERROR == WNetGetConnection(szWorkingPath, szRemoteName, &ulLength))
        {
            if ((_tcslen(szRemoteName) + _tcslen(szPath)) < MAX_PATH * 2)
            {
                _tcscat(szRemoteName, szPath);
                strPath = szRemoteName;
            }
        }
    }
}

//--------------------------------------------------------------------------
static BOOL ExtractSubString(CString& strOutput, CString strInput, LPCTSTR lpszSearchString, LPCTSTR lpszDelimiter)
{
	stringxi sInput(strInput), sOutput(strOutput), sSearchString(lpszSearchString), sDelimiter(lpszDelimiter);
	std::vector<stringxi> tokens;
	sInput.split(sDelimiter, tokens);	
	std::vector<stringxi>::const_iterator end = tokens.end();
	for (std::vector<stringxi>::const_iterator it = tokens.begin(); it != end; ++it)
	{
		std::vector<stringxi> keyValuePair;
		it->split(L"=", keyValuePair);
		if (keyValuePair[0] == sSearchString)
		{
			strOutput = it->c_str();
			return TRUE;
		}
	}
	return FALSE;
}

//------------------------------------------------------------------------------
static DATE GetFileDateTime(const CString& strFileName)
{
	DATE dtModifiedDate = 0;

    HANDLE hFile = CreateFile(strFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile != INVALID_HANDLE_VALUE)
	{
	    FILETIME ft;
		GetFileTime(hFile, NULL, NULL, &ft);
		CloseHandle(hFile);

		SYSTEMTIME st;
		FileTimeToSystemTime(&ft, &st);

		SystemTimeToVariantTime(&st, &dtModifiedDate);
	}
	return dtModifiedDate;
}

//------------------------------------------------------------------------------
static CString GetFileModifiedDateTime(HANDLE hFileHandle)
{
	CString strModifiedDateTime;

	if(hFileHandle != INVALID_HANDLE_VALUE)
	{
	    FILETIME ft;
		GetFileTime(hFileHandle, NULL, NULL, &ft);

		SYSTEMTIME st;
		FileTimeToSystemTime(&ft, &st);

		CS_ConvertDate(&st, strModifiedDateTime.GetBuffer(MAX_PATH));
		strModifiedDateTime.ReleaseBuffer();
	}
	return strModifiedDateTime;
}

//------------------------------------------------------------------------------
static CString GetFileModifiedDateTime(const CString& strFileName)
{
    HANDLE hFile = CreateFile(strFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	CString strModifiedDateTime;

	if(hFile != INVALID_HANDLE_VALUE)
	{
		strModifiedDateTime = GetFileModifiedDateTime(hFile);
		CloseHandle(hFile);
	}
	return strModifiedDateTime;
}

//------------------------------------------------------------------------------
static bool CS_GenerateSizeString(unsigned long ulSize, CString &strResults)
{
	strResults.Empty();

	unsigned long    lKilo = 1024;
	unsigned long    lMeg  = lKilo*lKilo;
	unsigned long	 lGig  = lMeg*lKilo;

    if (ulSize >= lGig)         
		 strResults.Format(_T("%ld.%1ld"),ulSize/lMeg,(ulSize%lMeg)/104858);
      else
        if (ulSize >= lKilo) //handle meg and kilo here
			strResults.Format(_T("%ld.%1ld"),ulSize/lKilo,(ulSize%lKilo)/103); 			
          else            
			strResults.Format(_T("0.%1ld"),ulSize/103);

	TCHAR  szOutput[255];
    if (0 != GetNumberFormat(LOCALE_USER_DEFAULT, 0, strResults, NULL, szOutput, 255))
        strResults = szOutput;

    if (ulSize >= lGig)
        strResults += _T(" MB");
      else
        strResults += _T(" KB");

    return true;
}

//------------------------------------------------------------------------------
#define GEN_UTIL_PACKAGE_QUERY_INCREMENT    100
static CString GetPackageQuery(const CSimpleArray<long> &arrPackages, long lStart = 0, long lEnd = -1)
{
    CString strTemp, strResults(_T("("));

    if (lEnd == -1)
        lEnd = arrPackages.m_nSize;
    for (long x = lStart; (x<lEnd)&&(x<arrPackages.m_nSize); x++)
    {
         strTemp.Format(_T("%ld,"), arrPackages[x]);
         strResults += strTemp;
    }

    if (strResults.GetLength() == 1)
        strResults.Empty();
      else
        strResults.SetAt(strResults.GetLength()-1, _T(')'));

    return strResults;
}

#endif 
