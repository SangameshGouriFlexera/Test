#ifndef _AsCoCreateInProc_H_
#define _AsCoCreateInProc_H_

// Used by the Standalone Build
// Create in-proc COM objects without using the registry

#include "stringx.h"

//#ifdef STANDALONE

#include <list>
#include <map>
using namespace std;

// Implementation: CASInProcManager is used to manage the inproc servers
class CASInProcManager
{
public:
	static CASInProcManager& Instance();
	static void Uninitialize();

	HRESULT GetClassObject(const stringx& sServer, REFCLSID rclsid,
		IClassFactory** ppClassFactory, bool bUseExePath = true);
	void FreeUnusedLibraries();

protected:
	CASInProcManager();
	~CASInProcManager();

private:
	static CASInProcManager* TheInstance;

	map<stringx, HMODULE> m_mapModules;
};
//#endif

// Implementation: ISCoCreateInstance (template function)
template <class Q>
HRESULT ASCoCreateInstance(const stringx& sServer, REFCLSID clsid, Q** pp, bool bUseExePath = true)
{
#ifdef STANDALONE
	CComPtr<IClassFactory> spClassFactory;
	HRESULT hres = CASInProcManager::Instance().GetClassObject(
		sServer, clsid, &spClassFactory, bUseExePath);
	if (FAILED(hres))
		return hres;
	return spClassFactory->CreateInstance(0, __uuidof(Q), (void**)pp);	
#else
	return ::CoCreateInstance(clsid, 0, CLSCTX_ALL, __uuidof(Q), (void**)pp);
#endif
}    


// DLL names to use with ASCoCreateInstance

#define ISUTIL_DLL			 L"system\\IsUtil.dll"
#define ISMMUPDATER2_DLL	 L"system\\IsMMUpdater2.dll"
#define ISWISCANNERS_DLL	 L"system\\IsWIScanners.dll"
#define ISMSIENTITY_DLL		 L"system\\IsMsiEntity.dll"
#define IMPORTEXPORT_DLL	 L"system\\ImportExport.dll"
#define PATCHDLL_DLL		 L"system\\PatchDLL.dll"
#define ISUPGRADE_DLL		 L"system\\IsUpgrade.dll"
#define ISAPPSERVICES_DLL    L"system\\IsAppServices.dll"
#define ISANALYZE_DLL		 L"system\\IsAnalyze.dll"
#define ISWIBUILD_DLL		 L"system\\IsWIBuild.dll"
#define INIREADER_DLL		 L"system\\IniReader.dll"
#define ISCOMMONSERVICES_DLL L"system\\IsCommonServices.dll"
#define MSITRANSFER_DLL		 L"system\\MsiTransfer.dll"
#define MERGEMOD_DLL 		 L"system\\Mergemod.dll"


#endif _AsCoCreateInProc_H_
