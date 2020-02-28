#ifndef _IsCoCreateInProc_H_
#define _IsCoCreateInProc_H_

// If you want to Debug VB, uncomment the Line Below
//#define DEBUG_VB

// Used by the Standalone Build
// Create in-proc COM objects without using the registry

#include "stringx.h"
#include "MIsCoCreateInProcConst.h"

#define NOSTANDALONE_DLL L""

#include <list>
#include <map>
using namespace std;

// Implementation: CInProcManager is used to manage the inproc servers
class CInProcManager
{
public:
	static CInProcManager& Instance();
	static void Uninitialize();

	HRESULT GetClassObject(const stringx& sServer, REFCLSID rclsid,
		IClassFactory** ppClassFactory);
	void FreeUnusedLibraries();
	stringx FindISSystemFolder(stringx sPath, const stringx& sServer);

protected:
	CInProcManager();
	~CInProcManager();

private:
	static CInProcManager* TheInstance;

	map<stringx, HMODULE> m_mapModules;
};


// Implementation: ISCoCreateInstance (template function)
template <class Q>
HRESULT ISCoCreateInstance(const stringx& sServer, REFCLSID clsid, Q** pp)
{
#ifdef DEBUG_VB
	return::CoCreateInstance(clsid, 0, CLSCTX_ALL, __uuidof(Q), (void**)pp);
#else
	if (!sServer.length())
	{
		return::CoCreateInstance(clsid, 0, CLSCTX_ALL, __uuidof(Q), (void**)pp);
	}
	CComPtr<IClassFactory> spClassFactory;
	HRESULT hres = CInProcManager::Instance().GetClassObject(sServer, clsid, &spClassFactory);
	if (FAILED(hres))
	{
#ifdef DEBUG
		LPOLESTR lpOleStr;
		::StringFromCLSID(clsid, &lpOleStr);
		stringx sMessage;
		sMessage.format(L"Could not load: %s\nCLSID:%s\nError:%x\n", sServer.c_str(), lpOleStr, hres);
		CoTaskMemFree(lpOleStr);
		::MessageBox(NULL, (LPCTSTR)sMessage, _T("InstallShield -- DEBUG ONLY"), MB_OK);
		// Chance to debug and see call stack here.
		ATLASSERT(0 == "Hit Retry to debug and see call stack here.");
#endif
		return hres;
	}
	return spClassFactory->CreateInstance(0, __uuidof(Q), (void**)pp);
#endif
}    

template <class Q>
HRESULT ISCoCreateInstance(const stringx& sServer, const stringx& sCLSID, Q** pp)
{
	CLSID clsid;
	::CLSIDFromString(CComBSTR(sCLSID.c_str()), &clsid);
	return ISCoCreateInstance(sServer, clsid, pp);
}

#ifdef STANDALONE

// Macro to preserve Standalone Build during future development
#define CoCreateInstance USE_ISCoCreateInstance_INSTEAD_PLEASE
#define CreateObject USE_ISCoCreateInstance_INSTEAD_PLEASE

#endif


#endif _IsCoCreateInProc_H_
