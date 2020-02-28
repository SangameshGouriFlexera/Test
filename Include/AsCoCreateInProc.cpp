// Used by the Standalone Build
// Create in-proc COM objects without using the registry

#include "stdafx.h"
#include "AsCoCreateInProc.h"
#include "pathx.h"

//#ifdef STANDALONE
CASInProcManager* CASInProcManager::TheInstance = 0;

#ifdef ASCOCREATE_USE_NEW_MODULE
//extern CAtlBaseModule _AtlBaseModule;
#else
extern CComModule _Module;
#endif

#pragma message("AsCoCreateInProc.cpp: if you get a linker error, make sure you define CComModule _Module; somewhere in your project.")

CASInProcManager::CASInProcManager()
{
	ATLASSERT(TheInstance == 0);
}	

CASInProcManager::~CASInProcManager()
{
	ATLASSERT(TheInstance == 0);
}	

CASInProcManager& CASInProcManager::Instance()
{
	if (!TheInstance)
	{
		TheInstance = new CASInProcManager;
	}
	return *TheInstance;
}	

void CASInProcManager::Uninitialize()
{
	CASInProcManager* pInstance = TheInstance;

	if (pInstance)
	{
		pInstance->FreeUnusedLibraries();

		// all libraries should be unloaded or else there is some dangling
		// refcount
//		ATLASSERT(pInstance->m_mapModules.empty());
	}

	TheInstance = 0;
	delete pInstance;
}	

void CASInProcManager::FreeUnusedLibraries()
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
			ATLTRACE(_T("CASInProcManager: Could not free library %s\n"),
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

HRESULT CASInProcManager::GetClassObject(const stringx& sServer, REFCLSID rclsid,
	IClassFactory** ppClassFactory, bool bUseExePath)
{
	// get the module, loading it if it hasn't been loaded already
	map<stringx, HMODULE>::iterator iterFind = m_mapModules.find(sServer);
	HMODULE hMod = 0;
	if (iterFind == m_mapModules.end())
	{
		is::pathx sFullPathServer;
			
		if (bUseExePath)
		{
			// always look for the server in the same directory as this server
			// NOT in the current directory, which may be different
			is::pathx sFilename;
#ifdef ASCOCREATE_USE_NEW_MODULE
            if (GetModuleFileName(_AtlBaseModule.GetModuleInstance(),
#else
			if (GetModuleFileName(_Module.GetModuleInstance(),
#endif
                sFilename.get_buffer(MAX_PATH), MAX_PATH))

			{
				sFullPathServer = sFilename.dir();
				sFullPathServer += sServer;

//				sFullPathServer = sFilename.path_dir();
//				sFullPathServer.path_append(sServer);

			}
			else
			{
				sFullPathServer = (LPCTSTR)sServer;
			}
		}
		else
		{
			sFullPathServer = (LPCTSTR)sServer;
		}

		hMod = ::LoadLibrary((LPCTSTR)sFullPathServer);
		if (!hMod)
		{
#ifdef DEBUG
			ASSERT(FALSE);

			DWORD dwError = GetLastError();
			CString msg;
			msg.Format(_T("%s, ErrorCode = %u"), (LPCTSTR) sFullPathServer, dwError);
			AfxMessageBox(msg);
#endif
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
//#endif
