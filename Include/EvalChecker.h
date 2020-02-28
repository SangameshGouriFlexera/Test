#include "stdafx.h"
#include <shlwapi.h>
#include <pathx.h>

#include "AdminStudio_RegLocations.h"

#pragma comment(lib, "shlwapi.lib")

namespace EvalCheck
{

	BOOL CanContinue(LPCTSTR lpszCommandLine)
	{
		// Get it from Registry
		BOOL bContinue = FALSE;
		HKEY hKey;
		DWORD dwType = 0;

		TCHAR szProductLocation[1024];
		DWORD dwSize = 1024;

		bool bCommonHelperDllFound = false;

		long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, AdmRegLocations::g_lpszHKLMMainSettingsKey, 0, KEY_READ, &hKey);
		if (lRet == ERROR_SUCCESS)
		{
			// get the Product location from Registry
			lRet = RegQueryValueEx(hKey, (LPCTSTR)AdmRegLocations::g_lpszProductLocation, NULL, &dwType, (LPBYTE)szProductLocation, &dwSize); 
			if (lRet == ERROR_SUCCESS)
			{
				::PathAppend(szProductLocation, AdmRegLocations::g_lpszCommonLocation);
				::PathAppend(szProductLocation, AdmRegLocations::g_lpszEvalChecker);

				is::pathx pthFileName = szProductLocation;

				if(pthFileName.exists(is::pathx::eptFile))
					bCommonHelperDllFound = true;
			}
		}

		HMODULE hLib = NULL;

		if(bCommonHelperDllFound)
			hLib = LoadLibrary(szProductLocation);
		else
			hLib = LoadLibrary(AdmRegLocations::g_lpszEvalChecker);

		if (hLib != NULL)
		{
			typedef BOOL (CALLBACK *CANCONTINUE)(BOOL);

			CANCONTINUE pDllExportedFunction = (CANCONTINUE)GetProcAddress(hLib, _T("CanContinue"));

			if (pDllExportedFunction)
			{
				BOOL bSilent = (_tcsstr(lpszCommandLine, _T("-ned")) == NULL) ? false : true;

				bContinue = (*pDllExportedFunction)(bSilent);
			}

			FreeLibrary(hLib);

			return bContinue;
		}
		else
		{
			AfxMessageBox("Error launching the evaluation version !!!");

			return bContinue;
		}
	}
};