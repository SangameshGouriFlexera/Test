#ifndef _COPY_POLICY_H
#define _COPY_POLICY_H

//	---------------------------------------------------------------------------
struct _CopyVariantFromAdaptBstr
{
	static HRESULT copy(VARIANT *pDest, CAdapt<CComBSTR> *pSource)
	{
		pDest->vt = VT_BSTR;
		pDest->bstrVal = pSource->m_T.Copy();
		return (pDest->bstrVal ? S_OK : E_POINTER);
	}
	static void init(VARIANT *pDest)
	{
		VariantInit(pDest);
	}
	static void destroy(VARIANT *pDest)
	{
		VariantClear(pDest);
	}
};

//	---------------------------------------------------------------------------
struct _CopyBstrFromAdaptBstr
{
	static HRESULT copy(BSTR *pDest, CAdapt<CComBSTR> *pSource)
	{
		*pDest = SysAllocString(pSource->m_T);
		return (pDest ? S_OK : E_OUTOFMEMORY);
	}
	static void init(BSTR *pDest)
	{
	}
	static void destroy(BSTR *pDest)
	{
		SysFreeString(*pDest);
	}
};


//	---------------------------------------------------------------------------
template<class T>
struct _CopyVariantFromAdaptItf
{
	static HRESULT copy(VARIANT *p1, const CAdapt< CComPtr<T> > * p2)
	{
		HRESULT hr = p2->m_T->QueryInterface(IID_IDispatch, (void**)&p1->pdispVal);
		if(SUCCEEDED(hr))
		{
			p1->vt = VT_DISPATCH;
		}
		else
		{
			hr = p2->m_T->QueryInterface(IID_IUnknown, (void**)&p1->punkVal);
			if(SUCCEEDED(hr))
			{
				p1->vt = VT_UNKNOWN;
			}
		}
		
		return hr;
	}
	static void init(VARIANT *p)
	{
		VariantInit(p);
	}
	static void destroy(VARIANT *p)
	{
		VariantClear(p);
	}

};

//	---------------------------------------------------------------------------
template<class T>
struct _CopyItfFromAdaptItf
{
	static HRESULT copy(T **p1, const CAdapt< CComPtr<T> > *p2)
	{
		if(*p1 = p2->m_T)
		{
			(*p1)->AddRef();
			return S_OK;
		}
		else
			return E_POINTER;
	}

	static void init(T ** p) {}
	static void destroy(T **p) 
	{
		if(*p)
			*p->Release();
	}

};

//	---------------------------------------------------------------------------
template<class T>
struct _CopyVariantFromItf
{
	static HRESULT copy(VARIANT *p1, T* p2)
	{
		HRESULT hr = p2->QueryInterface(IID_IDispatch, (void**)&p1->pdispVal);
		if(SUCCEEDED(hr))
		{
			p1->vt = VT_DISPATCH;
		}
		else
		{
			hr = p2->QueryInterface(IID_IUnknown, (void**)&p1->punkVal);
			if(SUCCEEDED(hr))
			{
				p1->vt = VT_UNKNOWN;
			}
		}
		
		return hr;
	}
	static void init(VARIANT *p)
	{
		VariantInit(p);
	}
	static void destroy(VARIANT *p)
	{
		VariantClear(p);
	}
};

//	---------------------------------------------------------------------------
// class GenericCopy
template <class DestinationType, class SourceType = DestinationType>
class GenericCopy
{
public :
	typedef DestinationType	destination_type;
	typedef SourceType		source_type;

	static void init(destination_type* p)
	{
		_Copy<destination_type>::init(p);
	}
	static void destroy(destination_type* p)
	{
		_Copy<destination_type>::destroy(p);
	}
	static HRESULT copy(destination_type* pTo, const source_type* pFrom)
	{
		return _Copy<destination_type>::copy(pTo, const_cast<source_type*>(pFrom));
	}

}; // class GenericCopy

//	---------------------------------------------------------------------------

#endif