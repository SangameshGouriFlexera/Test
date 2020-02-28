#if !defined _IS_VERIFYTRUST_H_
#define _IS_VERIFYTRUST_H_

class CVerifyTrust
{
public:

    CVerifyTrust() 
    {
    }

    ~CVerifyTrust() 
    {
    }

    bool IsTrustedFile(LPTSTR szFileName)
    {
        bool bSigned = false;

	    HMODULE hModule = LoadLibrary (_T("wintrust.dll"));
	    if (!hModule)
		    return bSigned;
	    
	    typedef LONG (WINAPI* TRUSTPROC)(HWND, GUID *, LPVOID);
	    TRUSTPROC pfnTructProc = (TRUSTPROC)GetProcAddress (hModule, _T("WinVerifyTrust"));
	    
	    static GUID	subjType	= {0xd17c5374, 0xa392, 0x11cf, {0x9d,0xf5,0,0xaa,0,0xc1,0x84,0xe0}};
	    static GUID	actionNoUI	= {0xc6b2e8d0, 0xe005, 0x11cf, {0xa1,0x34,0,0xc0,0x4f,0xd7,0xbf,0x43}};
	    static GUID	actionUI	= WIN_SPUB_ACTION_PUBLISHED_SOFTWARE;
	    
	    if (!pfnTructProc)
	    {
		    _ASSERTE(pfnTructProc != NULL);
		    return bSigned;
	    }
	    
	    DWORD res = 0;
	    
	    WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT	trustData;
	    WIN_TRUST_SUBJECT_FILE					subject;
	    
	    ZeroMemory (&trustData, sizeof(trustData));
	    ZeroMemory (&subject,	sizeof(subject));
	    
    #ifndef UNICODE
	    int len = MultiByteToWideChar (CP_OEMCP, 0, szFileName, -1, NULL, 0);
	    
	    subject.lpPath = new WCHAR[len+1];
	    MultiByteToWideChar (CP_OEMCP, 0, szFileName, -1, (LPWSTR)subject.lpPath, len);
    #else
	    subject.lpPath = new WCHAR[_tcslen(szFileName)+1];
	    _tcscpy (subject.lpPath, szFileName);
    #endif
	    subject.hFile = NULL;
	    
	    trustData.hClientToken	= NULL;
	    trustData.SubjectType	= &subjType;
	    trustData.Subject		= &subject;
	    
	    res = pfnTructProc((HWND)INVALID_HANDLE_VALUE, &actionUI, &trustData);
	    
	    if (subject.lpPath)
		    delete (LPWSTR)subject.lpPath;
	    
	    if (!res)
		    bSigned = true;

	    if (hModule)
		    ::FreeLibrary(hModule);
		    
	    return bSigned;	
    }
};

#endif