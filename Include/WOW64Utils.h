#ifndef __WOW64UTILS_H
#define __WOW64UTILS_H

#include <stack>

#ifndef PROCESSOR_ARCHITECTURE_AMD64
#define PROCESSOR_ARCHITECTURE_AMD64	9 // epic fail, i shouldn't have to define this
#endif

namespace WOW64Utils
{

static bool IsWow64()
{
	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE hProcess,PBOOL Wow64Process);
	typedef void (WINAPI *LPFN_GETNATIVESYSTEMINFO)(LPSYSTEM_INFO lpSystemInfo);

	SYSTEM_INFO sysInfo;
	BOOL bIsWow64 = FALSE;
	LPFN_ISWOW64PROCESS pIsWow64Process;
	LPFN_GETNATIVESYSTEMINFO pGetNativeSystemInfo;

	pGetNativeSystemInfo = (LPFN_GETNATIVESYSTEMINFO)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetNativeSystemInfo");
	pIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "IsWow64Process");

	if(!pGetNativeSystemInfo || !pIsWow64Process)
		return false;

	pGetNativeSystemInfo(&sysInfo);
	pIsWow64Process(GetCurrentProcess(), &bIsWow64);

	if(bIsWow64 && sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		return true;

	return false;
}

static std::stack<PVOID> g_stackWow64FsRedirect;

static void SetWOW64FsRedirection(bool bEnable)
{
	typedef BOOL (WINAPI *LPFN_WOW64ENABLEWOW64FSREDIRECTION)( BOOL bWow64FsEnableRedirection );
	typedef BOOL (WINAPI *LPFN_WOW64DISABLEWOW64FSREDIRECTION)( PVOID* OldValue );
	typedef BOOL (WINAPI *LPFN_WOW64REVERTWOW64FSREDIRECTION)( PVOID OldValue );

	if(!IsWow64())
		return ;

	LPFN_WOW64DISABLEWOW64FSREDIRECTION pWow64DisableWow64FsRedirection = (LPFN_WOW64DISABLEWOW64FSREDIRECTION)GetProcAddress(
		GetModuleHandle(_T("kernel32.dll")), "Wow64DisableWow64FsRedirection");
	LPFN_WOW64REVERTWOW64FSREDIRECTION pWow64RevertWow64FsRedirection = (LPFN_WOW64REVERTWOW64FSREDIRECTION)GetProcAddress(
		GetModuleHandle(_T("kernel32.dll")), "Wow64RevertWow64FsRedirection");

	if(pWow64DisableWow64FsRedirection && pWow64RevertWow64FsRedirection)
	{
		PVOID pOldRedirValue;

		if(!bEnable)
		{
			pWow64DisableWow64FsRedirection(&pOldRedirValue);
			g_stackWow64FsRedirect.push(pOldRedirValue);
		}
		else
		{
			_ASSERTE(!g_stackWow64FsRedirect.empty());

			pWow64RevertWow64FsRedirection(g_stackWow64FsRedirect.top());
			g_stackWow64FsRedirect.pop();
		}
	}
	else
	{
		LPFN_WOW64ENABLEWOW64FSREDIRECTION pWow64EnableWow64FsRedirection = (LPFN_WOW64ENABLEWOW64FSREDIRECTION)GetProcAddress(
			GetModuleHandle(_T("kernel32.dll")), "Wow64EnableWow64FsRedirection");

		_ASSERTE(pWow64EnableWow64FsRedirection);

		if(pWow64EnableWow64FsRedirection)
			pWow64EnableWow64FsRedirection(bEnable);
	}
}

static void GetSysWOW64Folder(LPTSTR lpszReturnValue, DWORD dwBufferSize)
{
#ifdef UNICODE
	typedef UINT (WINAPI *PGETSYSTEMWOW64DIRECTORYW)(LPWSTR, UINT);
#else
	typedef UINT (WINAPI *PGETSYSTEMWOW64DIRECTORYA)(LPSTR, UINT);
#endif

#ifdef UNICODE
	PGETSYSTEMWOW64DIRECTORYW pGetSystemWow64Directory = (PGETSYSTEMWOW64DIRECTORYW)GetProcAddress(
		GetModuleHandle(_T("kernel32.dll")),
		"GetSystemWow64DirectoryW");
#else
	PGETSYSTEMWOW64DIRECTORYA pGetSystemWow64Directory = (PGETSYSTEMWOW64DIRECTORYA)GetProcAddress(
		GetModuleHandle(_T("kernel32.dll")),
		"GetSystemWow64DirectoryA");
#endif

	//
	// Get the SysWOW64 folder path; note that if the API fails or is unavailable for some
	// reason, there is no fallback to a different path. We should have only gotten here if
	// we're on a 64-bit system, so the API better be available and succeed.
	//
	_ASSERTE(pGetSystemWow64Directory);

	if(pGetSystemWow64Directory)
		pGetSystemWow64Directory(lpszReturnValue, dwBufferSize);
}

}

#endif