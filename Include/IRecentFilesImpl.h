
#ifndef __IRECENTFILESIMPL_H_
#define __IRECENTFILESIMPL_H_

#include "RecentFilesBase.h"
#include "CopyPolicy.h"

typedef CComEnumOnSTL< IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, 
	_CopyVariantFromAdaptBstr, COMBSTRVECTOR >	CComEnumVariantOnBSTR;


/////////////////////////////////////////////////////////////////////////////
// IRecentFilesImpl
template<class T>
class IRecentFilesImpl : 
	public ICollectionOnSTLImpl<T, COMBSTRVECTOR, BSTR, _CopyBstrFromAdaptBstr, CComEnumVariantOnBSTR>,
	public CRecentFilesBase
{
public:
	typedef ICollectionOnSTLImpl<T, COMBSTRVECTOR, BSTR, 
		_CopyBstrFromAdaptBstr, CComEnumVariantOnBSTR>  ICollectionOnSTLImplBase;

	IRecentFilesImpl() : CRecentFilesBase(m_coll){}
	virtual ~IRecentFilesImpl() {};

public:
	STDMETHOD(Add)(/*[in]*/ BSTR bstrFileName, /*[out, retval]*/ BSTR *pbstrFileName);
	STDMETHOD(Remove)(/*[in]*/ VARIANT vItem);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pCount);
	STDMETHOD(get_Item)(/*[in]*/ long nItem, /*[out, retval]*/ BSTR *pbstrItem);
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ LPUNKNOWN* pVal);
};

/////////////////////////////////////////////////////////////////////////////
// IRecentFilesImpl

// --------------------------------------------------------------------------
//	Description: This function returns the number of files recently opened by the
//	user and saved in registry under
//	HKCU\\Software\\InstallShield\\<Product Name>\\<Recent File Key>
//	Parameters:
//		long *pCount = Return Value, Count of Recent Files
//
//	Returns: Number of files opened by the user
// --------------------------------------------------------------------------
template<class T>
STDMETHODIMP IRecentFilesImpl<T>::get_Count(long *pCount)
{
	CHECK_POINTER(pCount);

	TRY_ATL
	{
		HRESULT hr = GetRecentFilesList();
		CHECK_HRX(hr);

		hr = ICollectionOnSTLImplBase::get_Count(pCount);
		CHECK_HRX(hr);
	}
	CATCH_ATL

	return S_OK;
}


// --------------------------------------------------------------------------
//	Description: This function allows the user to get the file name stored in
//	recent file list registry key.
//
//	Parameters:
//		long nItem:	Index of the item to get
//		BSTR *pbstrItem: FileName at specified index
//
// --------------------------------------------------------------------------
template<class T>
STDMETHODIMP IRecentFilesImpl<T>::get_Item(long nItem, BSTR *pbstrItem)
{
	CHECK_OUT_POINTER(pbstrItem);

	TRY_ATL
	{
		HRESULT hr = GetRecentFilesList();
		CHECK_HRX(hr);
		
		hr = ICollectionOnSTLImplBase::get_Item(nItem, pbstrItem);
		CHECK_HRX(hr);
	}
	CATCH_ATL

	return S_OK;
}


// --------------------------------------------------------------------------
//	Description: This function returns the enumerator object for the collection
//
//	Parameters:
//		LPUNKNOWN *pVal - IUnknown pointer of the newly created enumerator object		
// --------------------------------------------------------------------------
template<class T>
STDMETHODIMP IRecentFilesImpl<T>::get__NewEnum(LPUNKNOWN* pVal)
{
	CHECK_OUT_POINTER(pVal);

	TRY_ATL
	{
		HRESULT hr = GetRecentFilesList();
		CHECK_HRX(hr);

		hr = ICollectionOnSTLImplBase::get__NewEnum(pVal);
		CHECK_HRX(hr);
	}
	CATCH_ATL

	return S_OK;
}


// --------------------------------------------------------------------------
template<class T>
STDMETHODIMP IRecentFilesImpl<T>::Add(/*[in]*/ BSTR bstrFileName, /*[out, retval]*/ BSTR *pbstrFileName)
{
	return CRecentFilesBase::Add(bstrFileName, pbstrFileName);
}

// --------------------------------------------------------------------------
template<class T>
STDMETHODIMP IRecentFilesImpl<T>::Remove(/*[in]*/ VARIANT vItem)
{
	return CRecentFilesBase::Remove(vItem);
}

#endif //__IRECENTFILESIMPL_H_
