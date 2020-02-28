// IVCOBJ.H : Include file for interface declaration for the VCOBJ module
//

#ifndef _IVCOBJ_H__INCLUDED
#define _IVCOBJ_H__INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// Definitions

#define FACILITY_VENICE					25
#define FACILITY_LIVEREG				26
#define FACILITY_ADVISOR				27

#define VENICE_E_NORESOURCEDLL			MAKE_HRESULT( SEVERITY_ERROR, FACILITY_VENICE, 1 )

//#define SAP_COMPANY					_T( "COMPANY" )
//#define SAP_PRODUCT					_T( "PRODUCT" )
//#define SAP_VERSION					_T( "VERSION" )
//#define SAP_LANGUAGE					_T( "LANGUAGE" )
#define SAP_SKU							_T( "SKU" )
#define SAP_PRODUCTNAME					_T( "Name" )
#define SAP_PRODUCTVERSION				_T( "Version" )
#define SAP_DISPLAYPRODUCT				_T( "DisplayProduct" )
#define SAP_DISPLAYVERSION				_T( "DisplayVersion" )
#define SAP_COPYRIGHT					_T( "Copyright" )
#define SAP_REGISTEREDTO				_T( "RegisteredTo" )
#define SAP_NOTICES						_T( "Notices" )
#define SAP_SUPPORT_PHONENUM			_T( "Support.PhoneNum" )
#define SAP_SUPPORT_WEBSITE				_T( "Support.WebSite" )
#define SAP_SUPPORT_EMAIL				_T( "Support.Email" )
#define SAP_LIVEUPDATE_CMD_LINE			_T( "LiveUpdate.CommandLine" )



/////////////////////////////////////////////////////////////////////////////
// Interface Declarations

// {172609A0-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( IID_IVcDialog, 
0x172609a0, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );

// {172609A1-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( IID_IVcStorage, 
0x172609a1, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );

// {172609A2-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( IID_IVcAboutBox, 
0x172609a2, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );
/*
// {172609A3-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( <<name>>, 
0x172609a3, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );

// {172609A4-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( <<name>>, 
0x172609a4, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );

// {172609A5-CA57-11d2-8274-0010AD122571}
DEFINE_GUID( <<name>>, 
0x172609a5, 0xca57, 0x11d2, 0x82, 0x74, 0x0, 0x10, 0xad, 0x12, 0x25, 0x71 );
*/



/////////////////////////////////////////////////////////////////////////////
// IVcDialog

DECLARE_INTERFACE_( IVcDialog, IUnknown )
{
	// IUnknown
	STDMETHODIMP QueryInterface( REFIID riid, LPVOID FAR* ppvObj ) PURE;
	STDMETHODIMP_(ULONG) AddRef() PURE;
	STDMETHODIMP_(ULONG) Release() PURE;

	// IVcDialog
	STDMETHOD(Invoke)( HWND hWndParent, DWORD dwFlags ) PURE;
};



/////////////////////////////////////////////////////////////////////////////
// IVcStorage

DECLARE_INTERFACE_( IVcStorage, IUnknown )
{
	// IUnknown
	STDMETHODIMP QueryInterface( REFIID riid, LPVOID FAR* ppvObj ) PURE;
	STDMETHODIMP_(ULONG) AddRef() PURE;
	STDMETHODIMP_(ULONG) Release() PURE;

	// IVcStorage
	STDMETHOD(GetValue)( LPCTSTR pszName, LPTSTR pszValue, UINT cchValue ) PURE;
	STDMETHOD(SetValue)( LPCTSTR pszName, LPCTSTR pszValue ) PURE;
};



/////////////////////////////////////////////////////////////////////////////
// IVcAboutBox

DECLARE_INTERFACE_( IVcAboutBox, IVcDialog )
{
	// IUnknown
	STDMETHODIMP QueryInterface( REFIID riid, LPVOID FAR* ppvObj ) PURE;
	STDMETHODIMP_(ULONG) AddRef() PURE;
	STDMETHODIMP_(ULONG) Release() PURE;

	// IVcDialog
	STDMETHOD(Invoke)( HWND hWndParent, DWORD dwFlags ) PURE;

	// IVcAboutBox ----------------------------------------------------------
	STDMETHOD(SetImage)( HANDLE hImage, WORD wImageType ) PURE;
	STDMETHOD(SetValue)( LPCTSTR pszName, LPCTSTR pszValue ) PURE;
	STDMETHOD(AddExtension)( REFCLSID classID ) PURE;
};



/////////////////////////////////////////////////////////////////////////////

#endif//#ifndef _IVCOBJ_H__INCLUDED
