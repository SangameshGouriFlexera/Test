#if !defined(_ISCOMUTILS_H_)
#define _ISCOMUTILS_H_

#include <atlbase.h>
#include "combool.h"

#ifndef __ISWACK
#include "MISCoCreateInProcConst.h" 

#ifdef VSIP
#include "..\src\ISWrkspcFrmWrk\FrmWrkLib\FrmWrkLib.h"
#define NO_STRINGX
#endif

#ifndef NO_STRINGX
#include "ISCoCreateInProc.h"
#endif 
#endif


#define BSTR2T(bstrVal) (bstrVal ? W2T(bstrVal) : TEXT(""))

#define OBJMGR_PROGID _T("ISObjMgr.ObjMgr2.1")
#define OBJMGR_VI_PROGID _T("ISObjMgr.ObjMgr2")

template <class Q>
HRESULT CreateObject(LPCOLESTR lpszProgID, Q** pp)
{
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(lpszProgID, &clsid);
    if (FAILED(hr)) return hr;
#ifdef STANDALONE
#undef CoCreateInstance
#endif
    return CoCreateInstance(clsid, 0, CLSCTX_ALL, __uuidof(Q), (void**)pp);
#ifdef STANDALONE
#define CoCreateInstance USE_ISCoCreateInstance_INSTEAD_PLEASE
#endif
}    


struct CDefaultVariant : public CComVariant
{
    CDefaultVariant()
    {
        ChangeType(VT_ERROR);
        scode = DISP_E_PARAMNOTFOUND;
    } 
};

#ifdef HRX_H
typedef HRX HRX_BOTH;
#else
#include "hrx_new.h"
typedef hrx HRX_BOTH;
#endif 

template <class TCollection, class TItem, class TEnumVariant = IEnumVARIANT,
		  typename TCount = unsigned long, typename TCountPointer = unsigned long*>
class enumeratorEx
{
public:
    enumeratorEx(TCollection* pCollection)

    {
		CComPtr<IUnknown> spUnk;
        HRX_BOTH hr = pCollection->get__NewEnum(&spUnk);
		hr = spUnk.QueryInterface(&m_spEnum);
    }
    bool next(CComPtr<TItem>& spItem)
    {
        spItem.Release();

        CComVariant varItem;
        TCount lFetched;
        HRX_BOTH hr = m_spEnum->Next(1, &varItem, (TCountPointer)&lFetched);
        if (lFetched == 0)
        {
            return false;
        }

        CComPtr<TItem> spDialog;
        if (V_VT(&varItem) == VT_DISPATCH)
        {
            CComPtr<IDispatch> spDisp = V_DISPATCH(&varItem);
            hr = spDisp.QueryInterface(&spItem);
        }
		else if (V_VT(&varItem) == VT_UNKNOWN)
		{
			CComPtr<IUnknown> spUnknown = V_UNKNOWN(&varItem);
            hr = spUnknown.QueryInterface(&spItem);
		}
        else
        {
            hr = E_FAIL;
        }
        return true;
    }
private:
    CComPtr<TEnumVariant> m_spEnum;
};

class CAutoBool
{
public:
    CAutoBool::CAutoBool(bool& bAutoBool)
        : m_bAutoBool(bAutoBool)
    {
        m_bAutoBool = true;
    }
    virtual ~CAutoBool()
    {
        m_bAutoBool = false;
    }
private:
    bool& m_bAutoBool;

};


// JLC 6/8/00
template <class T, const IID* piid = &__uuidof(T)>
struct is_com_cast : public CComQIPtr<T, piid>
{
	typedef CComQIPtr<T, piid> _Base;
	is_com_cast(T* lp) : _Base(lp) {}
	is_com_cast(const _Base& lp) : _Base(lp) {}
	is_com_cast(IUnknown* lp)
	{
		hrx hr;
		p=NULL;
		if (lp != NULL)
			hr = lp->QueryInterface(*piid, (void **)&p);
	}
};

#ifndef NO_STRINGX
template <class Q>
HRESULT AfxGetProcessApp(Q** pp)
{
	USES_CONVERSION;
    CComPtr<IDispatch> spObjMgr;
#ifdef __ISWACK
	HRESULT hr = CreateObject(T2W(OBJMGR_PROGID), &spObjMgr);
#else
	HRESULT hr = ISCoCreateInstance(ISOBJMGR_DLL, ISOBJMGR_COBJMGR, &spObjMgr);
#endif
    if (FAILED(hr)) return hr;

    DISPID dispId = -1;
    CComBSTR bstr= L"pApp";
    hr = spObjMgr->GetIDsOfNames(IID_NULL, &bstr, 1, LOCALE_SYSTEM_DEFAULT,
        &dispId);
    if (FAILED(hr)) return hr;
    if (dispId <= 0) return hr;

    CComVariant vApp;
    DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};
    hr = spObjMgr->Invoke(dispId, IID_NULL, LOCALE_USER_DEFAULT,
        DISPATCH_PROPERTYGET, &dispparamsNoArgs, &vApp, NULL, NULL);
    if (FAILED(hr)) return hr;
    
    if (V_VT(&vApp) != VT_UNKNOWN) return E_UNEXPECTED;

	if (V_UNKNOWN(&vApp))
	{
	    CComPtr<IUnknown> spUnkApp;
	    spUnkApp = V_UNKNOWN(&vApp);

	    return spUnkApp.QueryInterface(pp);
	}
	else
	{
		return S_OK;
	}
}
#endif

#ifdef VSIP
template <class Q>
HRESULT AfxGetProcessApp(Q** pp)
{
	USES_CONVERSION;

	CLSID clsid;
	::CLSIDFromString(CComBSTR(ISOBJMGR_COBJMGR), &clsid);

	CComPtr<IUnknown> spUnkObjMgr;
	HRESULT hr = DllCoCreateInstance(CComBSTR(ISOBJMGR_DLL), clsid, &spUnkObjMgr);
	if (FAILED(hr)) return hr;
	
	CComPtr<IDispatch> spObjMgr;
	hr = spUnkObjMgr.QueryInterface(&spObjMgr);
	if (FAILED(hr)) return hr;

    DISPID dispId = -1;
    CComBSTR bstr= L"pApp";
    hr = spObjMgr->GetIDsOfNames(IID_NULL, &bstr, 1, LOCALE_SYSTEM_DEFAULT,
        &dispId);
    if (FAILED(hr)) return hr;
    if (dispId <= 0) return hr;

    CComVariant vApp;
    DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};
    hr = spObjMgr->Invoke(dispId, IID_NULL, LOCALE_USER_DEFAULT,
        DISPATCH_PROPERTYGET, &dispparamsNoArgs, &vApp, NULL, NULL);
    if (FAILED(hr)) return hr;
    
    if (V_VT(&vApp) != VT_UNKNOWN) return E_UNEXPECTED;

	if (V_UNKNOWN(&vApp))
	{
	    CComPtr<IUnknown> spUnkApp;
	    spUnkApp = V_UNKNOWN(&vApp);

	    return spUnkApp.QueryInterface(pp);
	}
	else
	{
		return S_OK;
	}
}
#endif

#endif //_ISCOMUTILS_H_