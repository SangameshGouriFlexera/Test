// Used by the Standalone Build
// Create in-proc COM objects without using the registry

#include "stdafx.h"
#include "IsCoCreateInProc.h"

#pragma comment( lib, "shlwapi" )

#ifndef _ISDEV_USE_GLOBAL_MODULE_INSTANCE
#ifndef USE_ATL7_MODULES
	extern CComModule _Module;
#endif
#endif

#ifdef USE_ATL7_MODULES
#define _Module _AtlBaseModule
#endif

#include "pathx.h"

CInProcManager* CInProcManager::TheInstance = 0;

CInProcManager::CInProcManager()
{
	ATLASSERT(TheInstance == 0);
}	

CInProcManager::~CInProcManager()
{
	ATLASSERT(TheInstance == 0);
}	

CInProcManager& CInProcManager::Instance()
{
	if (!TheInstance)
	{
		TheInstance = new CInProcManager;
	}
	return *TheInstance;
}	

void CInProcManager::Uninitialize()
{
	CInProcManager* pInstance = TheInstance;

	if (pInstance)
	{
		pInstance->FreeUnusedLibraries();

		// all libraries should be unloaded or else there is some dangling
		// refcount
		ATLASSERT(pInstance->m_mapModules.empty());
	}

	TheInstance = 0;
	delete pInstance;
}	

void CInProcManager::FreeUnusedLibraries()
{
	// vector of modules that were freed
	list<stringx> vFreed;

	// iterate through all the currently loaded modules
	map<stringx, HMODULE>::iterator iter;
	for (iter = m_mapModules.begin(); iter != m_mapModules.end(); iter++)
	{
		HMODULE hMod = iter->second;
		
		// get the DllGetClassObject function.
		LPFNCANUNLOADNOW pfnCanUnloadNow = (LPFNCANUNLOADNOW)
			::GetProcAddress(hMod, "DllCanUnloadNow");

		// call it
		if (pfnCanUnloadNow && (pfnCanUnloadNow() == S_OK))
		{
			// add to the freed list
			vFreed.push_back(iter->first);
			
			// unload the module
			::FreeLibrary(hMod);
		}
		else
		{
			ATLTRACE(_T("CInProcManager: Could not free library %s\n"),
				(LPCTSTR)iter->first);
		}
	}

	// clean up the map
	list<stringx>::iterator iterList;
	for (iterList = vFreed.begin(); iterList != vFreed.end(); iterList++)
	{
		map<stringx, HMODULE>::iterator iterFind;
		iterFind = m_mapModules.find(*iterList);
		if (iterFind != m_mapModules.end())
		{
			m_mapModules.erase(iterFind);
		}
	}
}	

HRESULT CInProcManager::GetClassObject(const stringx& sServer, REFCLSID rclsid,
	IClassFactory** ppClassFactory)
{
	// get the module, loading it if it hasn't been loaded already
	map<stringx, HMODULE>::iterator iterFind = m_mapModules.find(sServer);
	HMODULE hMod = 0;
	if (iterFind == m_mapModules.end())
	{
		// always look for the server in the same directory as this server
		// NOT in the current directory, which may be different
		stringx sFilename;
		stringx sFullPathServer;
		stringx sSaveFullPathServer;

		bool bContainsBackslash = sServer.find(L"\\") == stringx::npos;
		HINSTANCE hInst = NULL;
#ifdef STANDALONE
		bContainsBackslash = false;
		hInst = _Module.GetModuleInstance();
#else
	#ifdef _ISDEV_USE_GLOBAL_MODULE_INSTANCE
		hInst = g_hInst;
	#else
		hInst = _Module.GetModuleInstance();
	#endif
#endif
		if (bContainsBackslash && 
			::GetModuleFileName(hInst, sFilename.get_buffer(MAX_PATH), MAX_PATH))
		{
			sFullPathServer = sFilename.path_dir();
			sFullPathServer.path_append(sServer);
			sSaveFullPathServer = sFullPathServer;

			// Look for File in ModuleLocation
			if (::GetFileAttributes((LPCTSTR) sFullPathServer) == -1)
			{
				sFullPathServer = sFilename.path_dir();
				sFullPathServer.path_append(L"System");
				sFullPathServer.path_append(sServer);
				// Look for File in ModuleLocation\System
				if (::GetFileAttributes((LPCTSTR) sFullPathServer) == -1)
				{
					sFullPathServer = is::pathx::special_folder(is::pathx::commonfiles).c_str();
					sFullPathServer.path_append(L"InstallShield"); 
					sFullPathServer.path_append(sServer);	
					// Look for File in [CommmonFiles]InstallShield
					if (::GetFileAttributes((LPCTSTR) sFullPathServer) == -1)
					{
						sFullPathServer = is::pathx::special_folder(is::pathx::commonfiles).c_str();
						sFullPathServer.path_append(L"InstallShield"); 
						sFullPathServer.path_append(L"DemoShield");
						sFullPathServer.path_append(sServer);

						// Look for File in [CommmonFiles]InstallShield\UpdateService
						if (::GetFileAttributes((LPCTSTR) sFullPathServer) == -1)
						{
							sFullPathServer = FindISSystemFolder(sSaveFullPathServer, sServer);
							if (::GetFileAttributes((LPCTSTR) sFullPathServer) == -1)
							{
								// If all else fails ... use the System Search Path
								sFullPathServer = sServer;
							}
						}
					}
				}
			}
		}
		else
		{
			sFullPathServer = sServer;
		}
		
		TCHAR szCurrentFolder[MAX_PATH];
		::GetCurrentDirectory(MAX_PATH, szCurrentFolder);
		::SetCurrentDirectory(sFullPathServer.path_dir());
		
		hMod = ::LoadLibrary(sFullPathServer);

		::SetCurrentDirectory(szCurrentFolder);
		
		if (!hMod)
		{
			return REGDB_E_CLASSNOTREG;
		}
		m_mapModules[sServer] = hMod;
	}
	else
	{
		hMod = iterFind->second;
	}

	// get the DllGetClassObject function.
	LPFNGETCLASSOBJECT pfnGetClassObject = (LPFNGETCLASSOBJECT)
		::GetProcAddress(hMod, "DllGetClassObject");
	if (!pfnGetClassObject)
	{
		return REGDB_E_CLASSNOTREG;
	}

	return pfnGetClassObject(rclsid, __uuidof(IClassFactory),
		(void**)ppClassFactory);
}	

stringx CInProcManager::FindISSystemFolder(stringx sFullPathServer, const stringx& sServer)
{
	// KEF 3/24/04 
	// I would use stringx functionality for this, but I don't trust it--see path_append
	// So instead, I have used Path APIs which are documented and work.

	TCHAR szTemp[MAX_PATH] = {0};

	::lstrcpy(szTemp, (LPCTSTR)sFullPathServer);

	// Trim off the file spec to make sure we have a path
	::PathRemoveFileSpec(szTemp);

	int nLength = ::lstrlen(szTemp);

	for (int i = nLength; i > 0 ; --i)
	{
		if (::PathIsRoot(szTemp))
			break;

		if (szTemp[i] == _T('\\') || szTemp[i] == _T('/'))
		{
			::PathAppend(szTemp, _T("System"));
			::PathAppend(szTemp, sServer);
			if (::PathFileExists(szTemp))
			{
				sFullPathServer = szTemp;
				break;
			}		
		}
		szTemp[i] = _T('\0');
	}
	return sFullPathServer;
}
