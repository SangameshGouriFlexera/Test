/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Aug 22 10:20:15 2014
 */
/* Compiler settings for ..\..\src\Backend\Shared\ISUtil\ISUtil.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ISUtil_h__
#define __ISUtil_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IExtractTypeLibrary_FWD_DEFINED__
#define __IExtractTypeLibrary_FWD_DEFINED__
typedef interface IExtractTypeLibrary IExtractTypeLibrary;
#endif 	/* __IExtractTypeLibrary_FWD_DEFINED__ */


#ifndef __IExtractContextType_FWD_DEFINED__
#define __IExtractContextType_FWD_DEFINED__
typedef interface IExtractContextType IExtractContextType;
#endif 	/* __IExtractContextType_FWD_DEFINED__ */


#ifndef __IExtractProgIDInfo_FWD_DEFINED__
#define __IExtractProgIDInfo_FWD_DEFINED__
typedef interface IExtractProgIDInfo IExtractProgIDInfo;
#endif 	/* __IExtractProgIDInfo_FWD_DEFINED__ */


#ifndef __IExtractVerbInfo_FWD_DEFINED__
#define __IExtractVerbInfo_FWD_DEFINED__
typedef interface IExtractVerbInfo IExtractVerbInfo;
#endif 	/* __IExtractVerbInfo_FWD_DEFINED__ */


#ifndef __IExtractVerbCol_FWD_DEFINED__
#define __IExtractVerbCol_FWD_DEFINED__
typedef interface IExtractVerbCol IExtractVerbCol;
#endif 	/* __IExtractVerbCol_FWD_DEFINED__ */


#ifndef __IExtractContextCol_FWD_DEFINED__
#define __IExtractContextCol_FWD_DEFINED__
typedef interface IExtractContextCol IExtractContextCol;
#endif 	/* __IExtractContextCol_FWD_DEFINED__ */


#ifndef __IExtractComClass_FWD_DEFINED__
#define __IExtractComClass_FWD_DEFINED__
typedef interface IExtractComClass IExtractComClass;
#endif 	/* __IExtractComClass_FWD_DEFINED__ */


#ifndef __IExtractExtensionInfo_FWD_DEFINED__
#define __IExtractExtensionInfo_FWD_DEFINED__
typedef interface IExtractExtensionInfo IExtractExtensionInfo;
#endif 	/* __IExtractExtensionInfo_FWD_DEFINED__ */


#ifndef __IExtractMIMEInfo_FWD_DEFINED__
#define __IExtractMIMEInfo_FWD_DEFINED__
typedef interface IExtractMIMEInfo IExtractMIMEInfo;
#endif 	/* __IExtractMIMEInfo_FWD_DEFINED__ */


#ifndef __IExtractMIMECol_FWD_DEFINED__
#define __IExtractMIMECol_FWD_DEFINED__
typedef interface IExtractMIMECol IExtractMIMECol;
#endif 	/* __IExtractMIMECol_FWD_DEFINED__ */


#ifndef __IExtractExtensionCol_FWD_DEFINED__
#define __IExtractExtensionCol_FWD_DEFINED__
typedef interface IExtractExtensionCol IExtractExtensionCol;
#endif 	/* __IExtractExtensionCol_FWD_DEFINED__ */


#ifndef __IExtractAppIDInfo_FWD_DEFINED__
#define __IExtractAppIDInfo_FWD_DEFINED__
typedef interface IExtractAppIDInfo IExtractAppIDInfo;
#endif 	/* __IExtractAppIDInfo_FWD_DEFINED__ */


#ifndef __IExtractTypeLibCol_FWD_DEFINED__
#define __IExtractTypeLibCol_FWD_DEFINED__
typedef interface IExtractTypeLibCol IExtractTypeLibCol;
#endif 	/* __IExtractTypeLibCol_FWD_DEFINED__ */


#ifndef __IExtractAppIDCol_FWD_DEFINED__
#define __IExtractAppIDCol_FWD_DEFINED__
typedef interface IExtractAppIDCol IExtractAppIDCol;
#endif 	/* __IExtractAppIDCol_FWD_DEFINED__ */


#ifndef __IExtractComClassCol_FWD_DEFINED__
#define __IExtractComClassCol_FWD_DEFINED__
typedef interface IExtractComClassCol IExtractComClassCol;
#endif 	/* __IExtractComClassCol_FWD_DEFINED__ */


#ifndef __IExtractProgIDCol_FWD_DEFINED__
#define __IExtractProgIDCol_FWD_DEFINED__
typedef interface IExtractProgIDCol IExtractProgIDCol;
#endif 	/* __IExtractProgIDCol_FWD_DEFINED__ */


#ifndef __IExtractComponent_FWD_DEFINED__
#define __IExtractComponent_FWD_DEFINED__
typedef interface IExtractComponent IExtractComponent;
#endif 	/* __IExtractComponent_FWD_DEFINED__ */


#ifndef __IISXferIconResource_FWD_DEFINED__
#define __IISXferIconResource_FWD_DEFINED__
typedef interface IISXferIconResource IISXferIconResource;
#endif 	/* __IISXferIconResource_FWD_DEFINED__ */


#ifndef __IServerInfoProgressEvent_FWD_DEFINED__
#define __IServerInfoProgressEvent_FWD_DEFINED__
typedef interface IServerInfoProgressEvent IServerInfoProgressEvent;
#endif 	/* __IServerInfoProgressEvent_FWD_DEFINED__ */


#ifndef __IServerInfoProgressEvent2_FWD_DEFINED__
#define __IServerInfoProgressEvent2_FWD_DEFINED__
typedef interface IServerInfoProgressEvent2 IServerInfoProgressEvent2;
#endif 	/* __IServerInfoProgressEvent2_FWD_DEFINED__ */


#ifndef __IFileSys_FWD_DEFINED__
#define __IFileSys_FWD_DEFINED__
typedef interface IFileSys IFileSys;
#endif 	/* __IFileSys_FWD_DEFINED__ */


#ifndef ___Collection_FWD_DEFINED__
#define ___Collection_FWD_DEFINED__
typedef interface _Collection _Collection;
#endif 	/* ___Collection_FWD_DEFINED__ */


#ifndef __IRegistry_FWD_DEFINED__
#define __IRegistry_FWD_DEFINED__
typedef interface IRegistry IRegistry;
#endif 	/* __IRegistry_FWD_DEFINED__ */


#ifndef __IGuid_FWD_DEFINED__
#define __IGuid_FWD_DEFINED__
typedef interface IGuid IGuid;
#endif 	/* __IGuid_FWD_DEFINED__ */


#ifndef __ISearchReplace_FWD_DEFINED__
#define __ISearchReplace_FWD_DEFINED__
typedef interface ISearchReplace ISearchReplace;
#endif 	/* __ISearchReplace_FWD_DEFINED__ */


#ifndef __IServerInfo_FWD_DEFINED__
#define __IServerInfo_FWD_DEFINED__
typedef interface IServerInfo IServerInfo;
#endif 	/* __IServerInfo_FWD_DEFINED__ */


#ifndef __IServerInfoIronwood_FWD_DEFINED__
#define __IServerInfoIronwood_FWD_DEFINED__
typedef interface IServerInfoIronwood IServerInfoIronwood;
#endif 	/* __IServerInfoIronwood_FWD_DEFINED__ */


#ifndef __IPropertyHeader_FWD_DEFINED__
#define __IPropertyHeader_FWD_DEFINED__
typedef interface IPropertyHeader IPropertyHeader;
#endif 	/* __IPropertyHeader_FWD_DEFINED__ */


#ifndef __IEncryptor_FWD_DEFINED__
#define __IEncryptor_FWD_DEFINED__
typedef interface IEncryptor IEncryptor;
#endif 	/* __IEncryptor_FWD_DEFINED__ */


#ifndef __ISignCodeEvent_FWD_DEFINED__
#define __ISignCodeEvent_FWD_DEFINED__
typedef interface ISignCodeEvent ISignCodeEvent;
#endif 	/* __ISignCodeEvent_FWD_DEFINED__ */


#ifndef __ISignCode_FWD_DEFINED__
#define __ISignCode_FWD_DEFINED__
typedef interface ISignCode ISignCode;
#endif 	/* __ISignCode_FWD_DEFINED__ */


#ifndef __IStampVersion_FWD_DEFINED__
#define __IStampVersion_FWD_DEFINED__
typedef interface IStampVersion IStampVersion;
#endif 	/* __IStampVersion_FWD_DEFINED__ */


#ifndef __IProgressNeptune_FWD_DEFINED__
#define __IProgressNeptune_FWD_DEFINED__
typedef interface IProgressNeptune IProgressNeptune;
#endif 	/* __IProgressNeptune_FWD_DEFINED__ */


#ifndef __IFileSys_FWD_DEFINED__
#define __IFileSys_FWD_DEFINED__
typedef interface IFileSys IFileSys;
#endif 	/* __IFileSys_FWD_DEFINED__ */


#ifndef __IFileSysNeptune_FWD_DEFINED__
#define __IFileSysNeptune_FWD_DEFINED__
typedef interface IFileSysNeptune IFileSysNeptune;
#endif 	/* __IFileSysNeptune_FWD_DEFINED__ */


#ifndef __SearchReplace_FWD_DEFINED__
#define __SearchReplace_FWD_DEFINED__

#ifdef __cplusplus
typedef class SearchReplace SearchReplace;
#else
typedef struct SearchReplace SearchReplace;
#endif /* __cplusplus */

#endif 	/* __SearchReplace_FWD_DEFINED__ */


#ifndef __Registry_FWD_DEFINED__
#define __Registry_FWD_DEFINED__

#ifdef __cplusplus
typedef class Registry Registry;
#else
typedef struct Registry Registry;
#endif /* __cplusplus */

#endif 	/* __Registry_FWD_DEFINED__ */


#ifndef __Guid_FWD_DEFINED__
#define __Guid_FWD_DEFINED__

#ifdef __cplusplus
typedef class Guid Guid;
#else
typedef struct Guid Guid;
#endif /* __cplusplus */

#endif 	/* __Guid_FWD_DEFINED__ */


#ifndef __File_FWD_DEFINED__
#define __File_FWD_DEFINED__

#ifdef __cplusplus
typedef class File File;
#else
typedef struct File File;
#endif /* __cplusplus */

#endif 	/* __File_FWD_DEFINED__ */


#ifndef __ISResXfer_FWD_DEFINED__
#define __ISResXfer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ISResXfer ISResXfer;
#else
typedef struct ISResXfer ISResXfer;
#endif /* __cplusplus */

#endif 	/* __ISResXfer_FWD_DEFINED__ */


#ifndef __ServerInfoEvents_FWD_DEFINED__
#define __ServerInfoEvents_FWD_DEFINED__
typedef interface ServerInfoEvents ServerInfoEvents;
#endif 	/* __ServerInfoEvents_FWD_DEFINED__ */


#ifndef __ServerInfo_FWD_DEFINED__
#define __ServerInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class ServerInfo ServerInfo;
#else
typedef struct ServerInfo ServerInfo;
#endif /* __cplusplus */

#endif 	/* __ServerInfo_FWD_DEFINED__ */


#ifndef __PropertyHeader_FWD_DEFINED__
#define __PropertyHeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertyHeader PropertyHeader;
#else
typedef struct PropertyHeader PropertyHeader;
#endif /* __cplusplus */

#endif 	/* __PropertyHeader_FWD_DEFINED__ */


#ifndef __Encryptor_FWD_DEFINED__
#define __Encryptor_FWD_DEFINED__

#ifdef __cplusplus
typedef class Encryptor Encryptor;
#else
typedef struct Encryptor Encryptor;
#endif /* __cplusplus */

#endif 	/* __Encryptor_FWD_DEFINED__ */


#ifndef __SignCode_FWD_DEFINED__
#define __SignCode_FWD_DEFINED__

#ifdef __cplusplus
typedef class SignCode SignCode;
#else
typedef struct SignCode SignCode;
#endif /* __cplusplus */

#endif 	/* __SignCode_FWD_DEFINED__ */


#ifndef __StampVersion_FWD_DEFINED__
#define __StampVersion_FWD_DEFINED__

#ifdef __cplusplus
typedef class StampVersion StampVersion;
#else
typedef struct StampVersion StampVersion;
#endif /* __cplusplus */

#endif 	/* __StampVersion_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_ISUtil_0000 */
/* [local] */ 

typedef /* [helpstring][uuid] */ 
enum ERegistryHives
    {	HKCR	= 0,
	HKCU	= 1,
	HKLM	= 2,
	HKU	= 3
    }	ERegistryHives;

typedef /* [helpstring][uuid] */ 
enum ERegistryDataTypes
    {	regNUMERIC	= 0,
	regSTRING	= 1,
	regVARIANT	= 2,
	regMULTISTRING	= 3,
	regEXPANDSTRING	= 4
    }	ERegistryDataTypes;

typedef /* [helpstring][uuid] */ 
enum ERegistryQueryTypes
    {	regKEYS	= 0,
	regNAMES	= 1
    }	ERegistryQueryTypes;

typedef /* [helpstring][uuid] */ 
enum EnumFileType
    {	eftEXE	= 0,
	eftDLL	= 1,
	eftICO	= 2,
	eftUnknown	= 100
    }	EnumFileType;




extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0000_v0_0_s_ifspec;

#ifndef __IExtractTypeLibrary_INTERFACE_DEFINED__
#define __IExtractTypeLibrary_INTERFACE_DEFINED__

/* interface IExtractTypeLibrary */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractTypeLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AC2A766-EC9C-4DE8-8F15-D05630AE74E4")
    IExtractTypeLibrary : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LibID( 
            /* [retval][out] */ BSTR __RPC_FAR *pLibID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LibID( 
            /* [in] */ BSTR LibID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LibLCID( 
            /* [retval][out] */ long __RPC_FAR *pLibLCID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LibLCID( 
            /* [in] */ long LibLCID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LibDescription( 
            /* [retval][out] */ BSTR __RPC_FAR *pLibDes) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LibDescription( 
            /* [in] */ BSTR pLibDes) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LibVersion( 
            /* [retval][out] */ BSTR __RPC_FAR *pLibVer) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LibVersion( 
            /* [in] */ BSTR pLibVer) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpDir( 
            /* [retval][out] */ BSTR __RPC_FAR *pHelpDir) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpDir( 
            /* [in] */ BSTR pHelpDir) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractTypeLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractTypeLibrary __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractTypeLibrary __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LibID )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pLibID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LibID )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ BSTR LibID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LibLCID )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pLibLCID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LibLCID )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ long LibLCID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LibDescription )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pLibDes);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LibDescription )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ BSTR pLibDes);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LibVersion )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pLibVer);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LibVersion )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ BSTR pLibVer);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpDir )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pHelpDir);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpDir )( 
            IExtractTypeLibrary __RPC_FAR * This,
            /* [in] */ BSTR pHelpDir);
        
        END_INTERFACE
    } IExtractTypeLibraryVtbl;

    interface IExtractTypeLibrary
    {
        CONST_VTBL struct IExtractTypeLibraryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractTypeLibrary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractTypeLibrary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractTypeLibrary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractTypeLibrary_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractTypeLibrary_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractTypeLibrary_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractTypeLibrary_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractTypeLibrary_get_LibID(This,pLibID)	\
    (This)->lpVtbl -> get_LibID(This,pLibID)

#define IExtractTypeLibrary_put_LibID(This,LibID)	\
    (This)->lpVtbl -> put_LibID(This,LibID)

#define IExtractTypeLibrary_get_LibLCID(This,pLibLCID)	\
    (This)->lpVtbl -> get_LibLCID(This,pLibLCID)

#define IExtractTypeLibrary_put_LibLCID(This,LibLCID)	\
    (This)->lpVtbl -> put_LibLCID(This,LibLCID)

#define IExtractTypeLibrary_get_LibDescription(This,pLibDes)	\
    (This)->lpVtbl -> get_LibDescription(This,pLibDes)

#define IExtractTypeLibrary_put_LibDescription(This,pLibDes)	\
    (This)->lpVtbl -> put_LibDescription(This,pLibDes)

#define IExtractTypeLibrary_get_LibVersion(This,pLibVer)	\
    (This)->lpVtbl -> get_LibVersion(This,pLibVer)

#define IExtractTypeLibrary_put_LibVersion(This,pLibVer)	\
    (This)->lpVtbl -> put_LibVersion(This,pLibVer)

#define IExtractTypeLibrary_get_HelpDir(This,pHelpDir)	\
    (This)->lpVtbl -> get_HelpDir(This,pHelpDir)

#define IExtractTypeLibrary_put_HelpDir(This,pHelpDir)	\
    (This)->lpVtbl -> put_HelpDir(This,pHelpDir)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_get_LibID_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pLibID);


void __RPC_STUB IExtractTypeLibrary_get_LibID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_put_LibID_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [in] */ BSTR LibID);


void __RPC_STUB IExtractTypeLibrary_put_LibID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_get_LibLCID_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pLibLCID);


void __RPC_STUB IExtractTypeLibrary_get_LibLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_put_LibLCID_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [in] */ long LibLCID);


void __RPC_STUB IExtractTypeLibrary_put_LibLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_get_LibDescription_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pLibDes);


void __RPC_STUB IExtractTypeLibrary_get_LibDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_put_LibDescription_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [in] */ BSTR pLibDes);


void __RPC_STUB IExtractTypeLibrary_put_LibDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_get_LibVersion_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pLibVer);


void __RPC_STUB IExtractTypeLibrary_get_LibVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_put_LibVersion_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [in] */ BSTR pLibVer);


void __RPC_STUB IExtractTypeLibrary_put_LibVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_get_HelpDir_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pHelpDir);


void __RPC_STUB IExtractTypeLibrary_get_HelpDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibrary_put_HelpDir_Proxy( 
    IExtractTypeLibrary __RPC_FAR * This,
    /* [in] */ BSTR pHelpDir);


void __RPC_STUB IExtractTypeLibrary_put_HelpDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractTypeLibrary_INTERFACE_DEFINED__ */


#ifndef __IExtractContextType_INTERFACE_DEFINED__
#define __IExtractContextType_INTERFACE_DEFINED__

/* interface IExtractContextType */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractContextType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5C28F79-4C46-42D5-A422-0B57160F5F19")
    IExtractContextType : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefInprocHandler( 
            /* [retval][out] */ long __RPC_FAR *lnDef) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefInprocHandler( 
            /* [in] */ long lnDef) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Argument( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrArgument) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Argument( 
            /* [in] */ BSTR bstrArgument) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractContextTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractContextType __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractContextType __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractContextType __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IExtractContextType __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefInprocHandler )( 
            IExtractContextType __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *lnDef);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefInprocHandler )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ long lnDef);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Argument )( 
            IExtractContextType __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrArgument);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Argument )( 
            IExtractContextType __RPC_FAR * This,
            /* [in] */ BSTR bstrArgument);
        
        END_INTERFACE
    } IExtractContextTypeVtbl;

    interface IExtractContextType
    {
        CONST_VTBL struct IExtractContextTypeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractContextType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractContextType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractContextType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractContextType_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractContextType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractContextType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractContextType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractContextType_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IExtractContextType_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IExtractContextType_get_DefInprocHandler(This,lnDef)	\
    (This)->lpVtbl -> get_DefInprocHandler(This,lnDef)

#define IExtractContextType_put_DefInprocHandler(This,lnDef)	\
    (This)->lpVtbl -> put_DefInprocHandler(This,lnDef)

#define IExtractContextType_get_Argument(This,bstrArgument)	\
    (This)->lpVtbl -> get_Argument(This,bstrArgument)

#define IExtractContextType_put_Argument(This,bstrArgument)	\
    (This)->lpVtbl -> put_Argument(This,bstrArgument)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractContextType_get_Name_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IExtractContextType_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractContextType_put_Name_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IExtractContextType_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractContextType_get_DefInprocHandler_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *lnDef);


void __RPC_STUB IExtractContextType_get_DefInprocHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractContextType_put_DefInprocHandler_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [in] */ long lnDef);


void __RPC_STUB IExtractContextType_put_DefInprocHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractContextType_get_Argument_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrArgument);


void __RPC_STUB IExtractContextType_get_Argument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractContextType_put_Argument_Proxy( 
    IExtractContextType __RPC_FAR * This,
    /* [in] */ BSTR bstrArgument);


void __RPC_STUB IExtractContextType_put_Argument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractContextType_INTERFACE_DEFINED__ */


#ifndef __IExtractProgIDInfo_INTERFACE_DEFINED__
#define __IExtractProgIDInfo_INTERFACE_DEFINED__

/* interface IExtractProgIDInfo */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractProgIDInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60B8EEA1-D3D6-4F4E-838B-9577648CBD8D")
    IExtractProgIDInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgID( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrProgID) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgID( 
            /* [in] */ BSTR bstrProgID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassID( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrclsid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClassID( 
            /* [in] */ BSTR bstrclsid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrDesc) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR bstrDesc) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ BSTR __RPC_FAR *pParent) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parent( 
            /* [in] */ BSTR pParent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultIcon( 
            /* [retval][out] */ BSTR __RPC_FAR *pFile) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultIcon( 
            /* [in] */ BSTR pFile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IconIndex( 
            /* [retval][out] */ long __RPC_FAR *pIndex) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IconIndex( 
            /* [in] */ long pIndex) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_VerbCollection( 
            /* [retval][out] */ IExtractVerbCol __RPC_FAR *__RPC_FAR *ppVerbCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractProgIDInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractProgIDInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractProgIDInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProgID )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrProgID);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProgID )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrProgID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClassID )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrclsid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ClassID )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrclsid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrDesc);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrDesc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pParent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Parent )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ BSTR pParent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultIcon )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pFile);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultIcon )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ BSTR pFile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IconIndex )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pIndex);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IconIndex )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [in] */ long pIndex);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VerbCollection )( 
            IExtractProgIDInfo __RPC_FAR * This,
            /* [retval][out] */ IExtractVerbCol __RPC_FAR *__RPC_FAR *ppVerbCol);
        
        END_INTERFACE
    } IExtractProgIDInfoVtbl;

    interface IExtractProgIDInfo
    {
        CONST_VTBL struct IExtractProgIDInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractProgIDInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractProgIDInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractProgIDInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractProgIDInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractProgIDInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractProgIDInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractProgIDInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractProgIDInfo_get_ProgID(This,bstrProgID)	\
    (This)->lpVtbl -> get_ProgID(This,bstrProgID)

#define IExtractProgIDInfo_put_ProgID(This,bstrProgID)	\
    (This)->lpVtbl -> put_ProgID(This,bstrProgID)

#define IExtractProgIDInfo_get_ClassID(This,bstrclsid)	\
    (This)->lpVtbl -> get_ClassID(This,bstrclsid)

#define IExtractProgIDInfo_put_ClassID(This,bstrclsid)	\
    (This)->lpVtbl -> put_ClassID(This,bstrclsid)

#define IExtractProgIDInfo_get_Description(This,bstrDesc)	\
    (This)->lpVtbl -> get_Description(This,bstrDesc)

#define IExtractProgIDInfo_put_Description(This,bstrDesc)	\
    (This)->lpVtbl -> put_Description(This,bstrDesc)

#define IExtractProgIDInfo_get_Parent(This,pParent)	\
    (This)->lpVtbl -> get_Parent(This,pParent)

#define IExtractProgIDInfo_put_Parent(This,pParent)	\
    (This)->lpVtbl -> put_Parent(This,pParent)

#define IExtractProgIDInfo_get_DefaultIcon(This,pFile)	\
    (This)->lpVtbl -> get_DefaultIcon(This,pFile)

#define IExtractProgIDInfo_put_DefaultIcon(This,pFile)	\
    (This)->lpVtbl -> put_DefaultIcon(This,pFile)

#define IExtractProgIDInfo_get_IconIndex(This,pIndex)	\
    (This)->lpVtbl -> get_IconIndex(This,pIndex)

#define IExtractProgIDInfo_put_IconIndex(This,pIndex)	\
    (This)->lpVtbl -> put_IconIndex(This,pIndex)

#define IExtractProgIDInfo_get_VerbCollection(This,ppVerbCol)	\
    (This)->lpVtbl -> get_VerbCollection(This,ppVerbCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_ProgID_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrProgID);


void __RPC_STUB IExtractProgIDInfo_get_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_ProgID_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrProgID);


void __RPC_STUB IExtractProgIDInfo_put_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_ClassID_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrclsid);


void __RPC_STUB IExtractProgIDInfo_get_ClassID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_ClassID_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrclsid);


void __RPC_STUB IExtractProgIDInfo_put_ClassID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_Description_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrDesc);


void __RPC_STUB IExtractProgIDInfo_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_Description_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrDesc);


void __RPC_STUB IExtractProgIDInfo_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_Parent_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pParent);


void __RPC_STUB IExtractProgIDInfo_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_Parent_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ BSTR pParent);


void __RPC_STUB IExtractProgIDInfo_put_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_DefaultIcon_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pFile);


void __RPC_STUB IExtractProgIDInfo_get_DefaultIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_DefaultIcon_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ BSTR pFile);


void __RPC_STUB IExtractProgIDInfo_put_DefaultIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_IconIndex_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pIndex);


void __RPC_STUB IExtractProgIDInfo_get_IconIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_put_IconIndex_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [in] */ long pIndex);


void __RPC_STUB IExtractProgIDInfo_put_IconIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExtractProgIDInfo_get_VerbCollection_Proxy( 
    IExtractProgIDInfo __RPC_FAR * This,
    /* [retval][out] */ IExtractVerbCol __RPC_FAR *__RPC_FAR *ppVerbCol);


void __RPC_STUB IExtractProgIDInfo_get_VerbCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractProgIDInfo_INTERFACE_DEFINED__ */


#ifndef __IExtractVerbInfo_INTERFACE_DEFINED__
#define __IExtractVerbInfo_INTERFACE_DEFINED__

/* interface IExtractVerbInfo */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractVerbInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("920BD788-E455-4FC5-BA7C-BEB2A6B30A7E")
    IExtractVerbInfo : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Verb( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Verb( 
            /* [in] */ BSTR pBstr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Command( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Command( 
            /* [in] */ BSTR pBstr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgID( 
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppProgID) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgID( 
            /* [in] */ IExtractProgIDInfo __RPC_FAR *pProgID) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Argument( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Argument( 
            /* [in] */ BSTR pBstr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Sequence( 
            /* [retval][out] */ long __RPC_FAR *pLn) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Sequence( 
            /* [in] */ long ln) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PEFile( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PEFile( 
            /* [in] */ BSTR pBstr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Extension( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Extension( 
            /* [in] */ BSTR pBstr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractVerbInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractVerbInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractVerbInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verb )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verb )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ BSTR pBstr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Command )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Command )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ BSTR pBstr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProgID )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppProgID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProgID )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ IExtractProgIDInfo __RPC_FAR *pProgID);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Argument )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Argument )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ BSTR pBstr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sequence )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pLn);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Sequence )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ long ln);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PEFile )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PEFile )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ BSTR pBstr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Extension )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Extension )( 
            IExtractVerbInfo __RPC_FAR * This,
            /* [in] */ BSTR pBstr);
        
        END_INTERFACE
    } IExtractVerbInfoVtbl;

    interface IExtractVerbInfo
    {
        CONST_VTBL struct IExtractVerbInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractVerbInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractVerbInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractVerbInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractVerbInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractVerbInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractVerbInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractVerbInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractVerbInfo_get_Verb(This,pBstr)	\
    (This)->lpVtbl -> get_Verb(This,pBstr)

#define IExtractVerbInfo_put_Verb(This,pBstr)	\
    (This)->lpVtbl -> put_Verb(This,pBstr)

#define IExtractVerbInfo_get_Command(This,pBstr)	\
    (This)->lpVtbl -> get_Command(This,pBstr)

#define IExtractVerbInfo_put_Command(This,pBstr)	\
    (This)->lpVtbl -> put_Command(This,pBstr)

#define IExtractVerbInfo_get_ProgID(This,ppProgID)	\
    (This)->lpVtbl -> get_ProgID(This,ppProgID)

#define IExtractVerbInfo_put_ProgID(This,pProgID)	\
    (This)->lpVtbl -> put_ProgID(This,pProgID)

#define IExtractVerbInfo_get_Argument(This,pBstr)	\
    (This)->lpVtbl -> get_Argument(This,pBstr)

#define IExtractVerbInfo_put_Argument(This,pBstr)	\
    (This)->lpVtbl -> put_Argument(This,pBstr)

#define IExtractVerbInfo_get_Sequence(This,pLn)	\
    (This)->lpVtbl -> get_Sequence(This,pLn)

#define IExtractVerbInfo_put_Sequence(This,ln)	\
    (This)->lpVtbl -> put_Sequence(This,ln)

#define IExtractVerbInfo_get_PEFile(This,pBstr)	\
    (This)->lpVtbl -> get_PEFile(This,pBstr)

#define IExtractVerbInfo_put_PEFile(This,pBstr)	\
    (This)->lpVtbl -> put_PEFile(This,pBstr)

#define IExtractVerbInfo_get_Extension(This,pBstr)	\
    (This)->lpVtbl -> get_Extension(This,pBstr)

#define IExtractVerbInfo_put_Extension(This,pBstr)	\
    (This)->lpVtbl -> put_Extension(This,pBstr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_Verb_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractVerbInfo_get_Verb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_Verb_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ BSTR pBstr);


void __RPC_STUB IExtractVerbInfo_put_Verb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_Command_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractVerbInfo_get_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_Command_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ BSTR pBstr);


void __RPC_STUB IExtractVerbInfo_put_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_ProgID_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppProgID);


void __RPC_STUB IExtractVerbInfo_get_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_ProgID_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ IExtractProgIDInfo __RPC_FAR *pProgID);


void __RPC_STUB IExtractVerbInfo_put_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_Argument_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractVerbInfo_get_Argument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_Argument_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ BSTR pBstr);


void __RPC_STUB IExtractVerbInfo_put_Argument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_Sequence_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pLn);


void __RPC_STUB IExtractVerbInfo_get_Sequence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_Sequence_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ long ln);


void __RPC_STUB IExtractVerbInfo_put_Sequence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_PEFile_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractVerbInfo_get_PEFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_PEFile_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ BSTR pBstr);


void __RPC_STUB IExtractVerbInfo_put_PEFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_get_Extension_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractVerbInfo_get_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IExtractVerbInfo_put_Extension_Proxy( 
    IExtractVerbInfo __RPC_FAR * This,
    /* [in] */ BSTR pBstr);


void __RPC_STUB IExtractVerbInfo_put_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractVerbInfo_INTERFACE_DEFINED__ */


#ifndef __IExtractVerbCol_INTERFACE_DEFINED__
#define __IExtractVerbCol_INTERFACE_DEFINED__

/* interface IExtractVerbCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractVerbCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFA25A58-BA01-4488-A838-F0FD3A0EADD6")
    IExtractVerbCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR VerbName,
            /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractVerbColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractVerbCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractVerbCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ BSTR VerbName,
            /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractVerbCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractVerbColVtbl;

    interface IExtractVerbCol
    {
        CONST_VTBL struct IExtractVerbColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractVerbCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractVerbCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractVerbCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractVerbCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractVerbCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractVerbCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractVerbCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractVerbCol_Add(This,VerbName,ppRef)	\
    (This)->lpVtbl -> Add(This,VerbName,ppRef)

#define IExtractVerbCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractVerbCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractVerbCol_Add_Proxy( 
    IExtractVerbCol __RPC_FAR * This,
    /* [in] */ BSTR VerbName,
    /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractVerbCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractVerbCol_get_Item_Proxy( 
    IExtractVerbCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractVerbInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractVerbCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractVerbCol_get_Count_Proxy( 
    IExtractVerbCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractVerbCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractVerbCol_INTERFACE_DEFINED__ */


#ifndef __IExtractContextCol_INTERFACE_DEFINED__
#define __IExtractContextCol_INTERFACE_DEFINED__

/* interface IExtractContextCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractContextCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0828B882-0BFB-4CA1-BA5F-237821E2BA4B")
    IExtractContextCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ContextName,
            /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractContextColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractContextCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractContextCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractContextCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ BSTR ContextName,
            /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractContextCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractContextCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractContextColVtbl;

    interface IExtractContextCol
    {
        CONST_VTBL struct IExtractContextColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractContextCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractContextCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractContextCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractContextCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractContextCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractContextCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractContextCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractContextCol_Add(This,ContextName,ppRef)	\
    (This)->lpVtbl -> Add(This,ContextName,ppRef)

#define IExtractContextCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractContextCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractContextCol_Add_Proxy( 
    IExtractContextCol __RPC_FAR * This,
    /* [in] */ BSTR ContextName,
    /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractContextCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractContextCol_get_Item_Proxy( 
    IExtractContextCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractContextType __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractContextCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractContextCol_get_Count_Proxy( 
    IExtractContextCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractContextCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractContextCol_INTERFACE_DEFINED__ */


#ifndef __IExtractComClass_INTERFACE_DEFINED__
#define __IExtractComClass_INTERFACE_DEFINED__

/* interface IExtractComClass */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractComClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF0B9602-78A9-43DC-B619-B531EDE82A1F")
    IExtractComClass : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [retval][out] */ BSTR __RPC_FAR *guid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Guid( 
            /* [in] */ BSTR guid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrDes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR bstrDes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgID( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrProgId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgID( 
            /* [in] */ BSTR bstrProgId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppID( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrAppID) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppID( 
            /* [in] */ BSTR bstrAppID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultIcon( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrDefIcon) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultIcon( 
            /* [in] */ BSTR bstrDefIcon) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IconIndex( 
            /* [retval][out] */ long __RPC_FAR *nIndex) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IconIndex( 
            /* [in] */ long nIndex) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ContextCol( 
            /* [retval][out] */ IExtractContextCol __RPC_FAR *__RPC_FAR *ppExtractContexCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractComClassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractComClass __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractComClass __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractComClass __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Guid )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *guid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Guid )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ BSTR guid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrDes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ BSTR bstrDes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProgID )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrProgId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProgID )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ BSTR bstrProgId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AppID )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrAppID);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AppID )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ BSTR bstrAppID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultIcon )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrDefIcon);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultIcon )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ BSTR bstrDefIcon);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IconIndex )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *nIndex);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IconIndex )( 
            IExtractComClass __RPC_FAR * This,
            /* [in] */ long nIndex);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ContextCol )( 
            IExtractComClass __RPC_FAR * This,
            /* [retval][out] */ IExtractContextCol __RPC_FAR *__RPC_FAR *ppExtractContexCol);
        
        END_INTERFACE
    } IExtractComClassVtbl;

    interface IExtractComClass
    {
        CONST_VTBL struct IExtractComClassVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractComClass_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractComClass_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractComClass_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractComClass_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractComClass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractComClass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractComClass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractComClass_get_Guid(This,guid)	\
    (This)->lpVtbl -> get_Guid(This,guid)

#define IExtractComClass_put_Guid(This,guid)	\
    (This)->lpVtbl -> put_Guid(This,guid)

#define IExtractComClass_get_Description(This,bstrDes)	\
    (This)->lpVtbl -> get_Description(This,bstrDes)

#define IExtractComClass_put_Description(This,bstrDes)	\
    (This)->lpVtbl -> put_Description(This,bstrDes)

#define IExtractComClass_get_ProgID(This,bstrProgId)	\
    (This)->lpVtbl -> get_ProgID(This,bstrProgId)

#define IExtractComClass_put_ProgID(This,bstrProgId)	\
    (This)->lpVtbl -> put_ProgID(This,bstrProgId)

#define IExtractComClass_get_AppID(This,bstrAppID)	\
    (This)->lpVtbl -> get_AppID(This,bstrAppID)

#define IExtractComClass_put_AppID(This,bstrAppID)	\
    (This)->lpVtbl -> put_AppID(This,bstrAppID)

#define IExtractComClass_get_DefaultIcon(This,bstrDefIcon)	\
    (This)->lpVtbl -> get_DefaultIcon(This,bstrDefIcon)

#define IExtractComClass_put_DefaultIcon(This,bstrDefIcon)	\
    (This)->lpVtbl -> put_DefaultIcon(This,bstrDefIcon)

#define IExtractComClass_get_IconIndex(This,nIndex)	\
    (This)->lpVtbl -> get_IconIndex(This,nIndex)

#define IExtractComClass_put_IconIndex(This,nIndex)	\
    (This)->lpVtbl -> put_IconIndex(This,nIndex)

#define IExtractComClass_get_ContextCol(This,ppExtractContexCol)	\
    (This)->lpVtbl -> get_ContextCol(This,ppExtractContexCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_Guid_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *guid);


void __RPC_STUB IExtractComClass_get_Guid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_Guid_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ BSTR guid);


void __RPC_STUB IExtractComClass_put_Guid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_Description_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrDes);


void __RPC_STUB IExtractComClass_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_Description_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ BSTR bstrDes);


void __RPC_STUB IExtractComClass_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_ProgID_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrProgId);


void __RPC_STUB IExtractComClass_get_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_ProgID_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ BSTR bstrProgId);


void __RPC_STUB IExtractComClass_put_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_AppID_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrAppID);


void __RPC_STUB IExtractComClass_get_AppID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_AppID_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ BSTR bstrAppID);


void __RPC_STUB IExtractComClass_put_AppID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_DefaultIcon_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrDefIcon);


void __RPC_STUB IExtractComClass_get_DefaultIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_DefaultIcon_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ BSTR bstrDefIcon);


void __RPC_STUB IExtractComClass_put_DefaultIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_IconIndex_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *nIndex);


void __RPC_STUB IExtractComClass_get_IconIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractComClass_put_IconIndex_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [in] */ long nIndex);


void __RPC_STUB IExtractComClass_put_IconIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComClass_get_ContextCol_Proxy( 
    IExtractComClass __RPC_FAR * This,
    /* [retval][out] */ IExtractContextCol __RPC_FAR *__RPC_FAR *ppExtractContexCol);


void __RPC_STUB IExtractComClass_get_ContextCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractComClass_INTERFACE_DEFINED__ */


#ifndef __IExtractExtensionInfo_INTERFACE_DEFINED__
#define __IExtractExtensionInfo_INTERFACE_DEFINED__

/* interface IExtractExtensionInfo */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractExtensionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE1895CA-FEF4-4E11-9CA0-C89CE7804ED0")
    IExtractExtensionInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Extension( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Extension( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgID( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgID( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MIME( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MIME( 
            /* [in] */ BSTR bstr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractExtensionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractExtensionInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractExtensionInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Extension )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Extension )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProgID )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProgID )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MIME )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MIME )( 
            IExtractExtensionInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        END_INTERFACE
    } IExtractExtensionInfoVtbl;

    interface IExtractExtensionInfo
    {
        CONST_VTBL struct IExtractExtensionInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractExtensionInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractExtensionInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractExtensionInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractExtensionInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractExtensionInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractExtensionInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractExtensionInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractExtensionInfo_get_Extension(This,pBstr)	\
    (This)->lpVtbl -> get_Extension(This,pBstr)

#define IExtractExtensionInfo_put_Extension(This,bstr)	\
    (This)->lpVtbl -> put_Extension(This,bstr)

#define IExtractExtensionInfo_get_ProgID(This,pBstr)	\
    (This)->lpVtbl -> get_ProgID(This,pBstr)

#define IExtractExtensionInfo_put_ProgID(This,bstr)	\
    (This)->lpVtbl -> put_ProgID(This,bstr)

#define IExtractExtensionInfo_get_MIME(This,pBstr)	\
    (This)->lpVtbl -> get_MIME(This,pBstr)

#define IExtractExtensionInfo_put_MIME(This,bstr)	\
    (This)->lpVtbl -> put_MIME(This,bstr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_get_Extension_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractExtensionInfo_get_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_put_Extension_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractExtensionInfo_put_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_get_ProgID_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractExtensionInfo_get_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_put_ProgID_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractExtensionInfo_put_ProgID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_get_MIME_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractExtensionInfo_get_MIME_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractExtensionInfo_put_MIME_Proxy( 
    IExtractExtensionInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractExtensionInfo_put_MIME_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractExtensionInfo_INTERFACE_DEFINED__ */


#ifndef __IExtractMIMEInfo_INTERFACE_DEFINED__
#define __IExtractMIMEInfo_INTERFACE_DEFINED__

/* interface IExtractMIMEInfo */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractMIMEInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F51D4F27-ACD7-4A85-BDD4-353702ECC301")
    IExtractMIMEInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Extension( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Extension( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Content( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Content( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CLSID( 
            /* [retval][out] */ BSTR __RPC_FAR *pBstr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CLSID( 
            /* [in] */ BSTR bstr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractMIMEInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractMIMEInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractMIMEInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Extension )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Extension )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Content )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Content )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CLSID )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pBstr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CLSID )( 
            IExtractMIMEInfo __RPC_FAR * This,
            /* [in] */ BSTR bstr);
        
        END_INTERFACE
    } IExtractMIMEInfoVtbl;

    interface IExtractMIMEInfo
    {
        CONST_VTBL struct IExtractMIMEInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractMIMEInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractMIMEInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractMIMEInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractMIMEInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractMIMEInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractMIMEInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractMIMEInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractMIMEInfo_get_Extension(This,pBstr)	\
    (This)->lpVtbl -> get_Extension(This,pBstr)

#define IExtractMIMEInfo_put_Extension(This,bstr)	\
    (This)->lpVtbl -> put_Extension(This,bstr)

#define IExtractMIMEInfo_get_Content(This,pBstr)	\
    (This)->lpVtbl -> get_Content(This,pBstr)

#define IExtractMIMEInfo_put_Content(This,bstr)	\
    (This)->lpVtbl -> put_Content(This,bstr)

#define IExtractMIMEInfo_get_CLSID(This,pBstr)	\
    (This)->lpVtbl -> get_CLSID(This,pBstr)

#define IExtractMIMEInfo_put_CLSID(This,bstr)	\
    (This)->lpVtbl -> put_CLSID(This,bstr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_get_Extension_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractMIMEInfo_get_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_put_Extension_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractMIMEInfo_put_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_get_Content_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractMIMEInfo_get_Content_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_put_Content_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractMIMEInfo_put_Content_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_get_CLSID_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pBstr);


void __RPC_STUB IExtractMIMEInfo_get_CLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractMIMEInfo_put_CLSID_Proxy( 
    IExtractMIMEInfo __RPC_FAR * This,
    /* [in] */ BSTR bstr);


void __RPC_STUB IExtractMIMEInfo_put_CLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractMIMEInfo_INTERFACE_DEFINED__ */


#ifndef __IExtractMIMECol_INTERFACE_DEFINED__
#define __IExtractMIMECol_INTERFACE_DEFINED__

/* interface IExtractMIMECol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractMIMECol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("963DFB94-14EF-41C9-864F-B82B559A5D8D")
    IExtractMIMECol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR bstrMIME,
            /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractMIMEColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractMIMECol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractMIMECol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ BSTR bstrMIME,
            /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractMIMECol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractMIMEColVtbl;

    interface IExtractMIMECol
    {
        CONST_VTBL struct IExtractMIMEColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractMIMECol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractMIMECol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractMIMECol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractMIMECol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractMIMECol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractMIMECol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractMIMECol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractMIMECol_Add(This,bstrMIME,ppRef)	\
    (This)->lpVtbl -> Add(This,bstrMIME,ppRef)

#define IExtractMIMECol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractMIMECol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractMIMECol_Add_Proxy( 
    IExtractMIMECol __RPC_FAR * This,
    /* [in] */ BSTR bstrMIME,
    /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractMIMECol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractMIMECol_get_Item_Proxy( 
    IExtractMIMECol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractMIMEInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractMIMECol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractMIMECol_get_Count_Proxy( 
    IExtractMIMECol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractMIMECol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractMIMECol_INTERFACE_DEFINED__ */


#ifndef __IExtractExtensionCol_INTERFACE_DEFINED__
#define __IExtractExtensionCol_INTERFACE_DEFINED__

/* interface IExtractExtensionCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractExtensionCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B433E4B4-F62B-4E33-AE44-1A242EF9B18A")
    IExtractExtensionCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR bstrExt,
            /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractExtensionColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractExtensionCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractExtensionCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ BSTR bstrExt,
            /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractExtensionCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractExtensionColVtbl;

    interface IExtractExtensionCol
    {
        CONST_VTBL struct IExtractExtensionColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractExtensionCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractExtensionCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractExtensionCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractExtensionCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractExtensionCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractExtensionCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractExtensionCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractExtensionCol_Add(This,bstrExt,ppRef)	\
    (This)->lpVtbl -> Add(This,bstrExt,ppRef)

#define IExtractExtensionCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractExtensionCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractExtensionCol_Add_Proxy( 
    IExtractExtensionCol __RPC_FAR * This,
    /* [in] */ BSTR bstrExt,
    /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractExtensionCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractExtensionCol_get_Item_Proxy( 
    IExtractExtensionCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractExtensionInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractExtensionCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractExtensionCol_get_Count_Proxy( 
    IExtractExtensionCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractExtensionCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractExtensionCol_INTERFACE_DEFINED__ */


#ifndef __IExtractAppIDInfo_INTERFACE_DEFINED__
#define __IExtractAppIDInfo_INTERFACE_DEFINED__

/* interface IExtractAppIDInfo */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractAppIDInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F953CFD4-5D6F-48DC-A723-A3B2E4B70D3C")
    IExtractAppIDInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GUID( 
            /* [retval][out] */ BSTR __RPC_FAR *Guid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GUID( 
            /* [in] */ BSTR Guid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteServerName( 
            /* [retval][out] */ BSTR __RPC_FAR *rsName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoteServerName( 
            /* [in] */ BSTR rsName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalService( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrLService) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalService( 
            /* [in] */ BSTR bstrLService) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceParameters( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrServParam) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServiceParameters( 
            /* [in] */ BSTR bstrServParam) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DllSurrogate( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrsur) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DllSurrogate( 
            /* [in] */ BSTR bstrsur) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrDesc) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR bstrDesc) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivateAtStorage( 
            /* [retval][out] */ long __RPC_FAR *lnActi) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivateAtStorage( 
            /* [in] */ long lnActi) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RunAsInteractiveUser( 
            /* [retval][out] */ long __RPC_FAR *lnRun) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RunAsInteractiveUser( 
            /* [in] */ long lnRun) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractAppIDInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractAppIDInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractAppIDInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GUID )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Guid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GUID )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR Guid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RemoteServerName )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *rsName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RemoteServerName )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR rsName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocalService )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrLService);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LocalService )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrLService);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceParameters )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrServParam);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ServiceParameters )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrServParam);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DllSurrogate )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrsur);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DllSurrogate )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrsur);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrDesc);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ BSTR bstrDesc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateAtStorage )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *lnActi);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateAtStorage )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ long lnActi);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RunAsInteractiveUser )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *lnRun);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RunAsInteractiveUser )( 
            IExtractAppIDInfo __RPC_FAR * This,
            /* [in] */ long lnRun);
        
        END_INTERFACE
    } IExtractAppIDInfoVtbl;

    interface IExtractAppIDInfo
    {
        CONST_VTBL struct IExtractAppIDInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractAppIDInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractAppIDInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractAppIDInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractAppIDInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractAppIDInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractAppIDInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractAppIDInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractAppIDInfo_get_GUID(This,Guid)	\
    (This)->lpVtbl -> get_GUID(This,Guid)

#define IExtractAppIDInfo_put_GUID(This,Guid)	\
    (This)->lpVtbl -> put_GUID(This,Guid)

#define IExtractAppIDInfo_get_RemoteServerName(This,rsName)	\
    (This)->lpVtbl -> get_RemoteServerName(This,rsName)

#define IExtractAppIDInfo_put_RemoteServerName(This,rsName)	\
    (This)->lpVtbl -> put_RemoteServerName(This,rsName)

#define IExtractAppIDInfo_get_LocalService(This,bstrLService)	\
    (This)->lpVtbl -> get_LocalService(This,bstrLService)

#define IExtractAppIDInfo_put_LocalService(This,bstrLService)	\
    (This)->lpVtbl -> put_LocalService(This,bstrLService)

#define IExtractAppIDInfo_get_ServiceParameters(This,bstrServParam)	\
    (This)->lpVtbl -> get_ServiceParameters(This,bstrServParam)

#define IExtractAppIDInfo_put_ServiceParameters(This,bstrServParam)	\
    (This)->lpVtbl -> put_ServiceParameters(This,bstrServParam)

#define IExtractAppIDInfo_get_DllSurrogate(This,bstrsur)	\
    (This)->lpVtbl -> get_DllSurrogate(This,bstrsur)

#define IExtractAppIDInfo_put_DllSurrogate(This,bstrsur)	\
    (This)->lpVtbl -> put_DllSurrogate(This,bstrsur)

#define IExtractAppIDInfo_get_Description(This,bstrDesc)	\
    (This)->lpVtbl -> get_Description(This,bstrDesc)

#define IExtractAppIDInfo_put_Description(This,bstrDesc)	\
    (This)->lpVtbl -> put_Description(This,bstrDesc)

#define IExtractAppIDInfo_get_ActivateAtStorage(This,lnActi)	\
    (This)->lpVtbl -> get_ActivateAtStorage(This,lnActi)

#define IExtractAppIDInfo_put_ActivateAtStorage(This,lnActi)	\
    (This)->lpVtbl -> put_ActivateAtStorage(This,lnActi)

#define IExtractAppIDInfo_get_RunAsInteractiveUser(This,lnRun)	\
    (This)->lpVtbl -> get_RunAsInteractiveUser(This,lnRun)

#define IExtractAppIDInfo_put_RunAsInteractiveUser(This,lnRun)	\
    (This)->lpVtbl -> put_RunAsInteractiveUser(This,lnRun)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_GUID_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Guid);


void __RPC_STUB IExtractAppIDInfo_get_GUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_GUID_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR Guid);


void __RPC_STUB IExtractAppIDInfo_put_GUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_RemoteServerName_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *rsName);


void __RPC_STUB IExtractAppIDInfo_get_RemoteServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_RemoteServerName_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR rsName);


void __RPC_STUB IExtractAppIDInfo_put_RemoteServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_LocalService_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrLService);


void __RPC_STUB IExtractAppIDInfo_get_LocalService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_LocalService_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrLService);


void __RPC_STUB IExtractAppIDInfo_put_LocalService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_ServiceParameters_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrServParam);


void __RPC_STUB IExtractAppIDInfo_get_ServiceParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_ServiceParameters_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrServParam);


void __RPC_STUB IExtractAppIDInfo_put_ServiceParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_DllSurrogate_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrsur);


void __RPC_STUB IExtractAppIDInfo_get_DllSurrogate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_DllSurrogate_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrsur);


void __RPC_STUB IExtractAppIDInfo_put_DllSurrogate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_Description_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrDesc);


void __RPC_STUB IExtractAppIDInfo_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_Description_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ BSTR bstrDesc);


void __RPC_STUB IExtractAppIDInfo_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_ActivateAtStorage_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *lnActi);


void __RPC_STUB IExtractAppIDInfo_get_ActivateAtStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_ActivateAtStorage_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ long lnActi);


void __RPC_STUB IExtractAppIDInfo_put_ActivateAtStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_get_RunAsInteractiveUser_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *lnRun);


void __RPC_STUB IExtractAppIDInfo_get_RunAsInteractiveUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExtractAppIDInfo_put_RunAsInteractiveUser_Proxy( 
    IExtractAppIDInfo __RPC_FAR * This,
    /* [in] */ long lnRun);


void __RPC_STUB IExtractAppIDInfo_put_RunAsInteractiveUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractAppIDInfo_INTERFACE_DEFINED__ */


#ifndef __IExtractTypeLibCol_INTERFACE_DEFINED__
#define __IExtractTypeLibCol_INTERFACE_DEFINED__

/* interface IExtractTypeLibCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractTypeLibCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64D94CF0-83FD-4237-95B4-5A963FEEBE7D")
    IExtractTypeLibCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR TypeLibID,
            /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractTypeLibColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractTypeLibCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractTypeLibCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ BSTR TypeLibID,
            /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractTypeLibCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractTypeLibColVtbl;

    interface IExtractTypeLibCol
    {
        CONST_VTBL struct IExtractTypeLibColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractTypeLibCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractTypeLibCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractTypeLibCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractTypeLibCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractTypeLibCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractTypeLibCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractTypeLibCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractTypeLibCol_Add(This,TypeLibID,ppRef)	\
    (This)->lpVtbl -> Add(This,TypeLibID,ppRef)

#define IExtractTypeLibCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractTypeLibCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibCol_Add_Proxy( 
    IExtractTypeLibCol __RPC_FAR * This,
    /* [in] */ BSTR TypeLibID,
    /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractTypeLibCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibCol_get_Item_Proxy( 
    IExtractTypeLibCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractTypeLibrary __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractTypeLibCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractTypeLibCol_get_Count_Proxy( 
    IExtractTypeLibCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractTypeLibCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractTypeLibCol_INTERFACE_DEFINED__ */


#ifndef __IExtractAppIDCol_INTERFACE_DEFINED__
#define __IExtractAppIDCol_INTERFACE_DEFINED__

/* interface IExtractAppIDCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractAppIDCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FBC329C0-52F4-4FEF-85AD-40521EA2324B")
    IExtractAppIDCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR AppID,
            /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractAppIDColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractAppIDCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractAppIDCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ BSTR AppID,
            /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractAppIDCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractAppIDColVtbl;

    interface IExtractAppIDCol
    {
        CONST_VTBL struct IExtractAppIDColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractAppIDCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractAppIDCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractAppIDCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractAppIDCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractAppIDCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractAppIDCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractAppIDCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractAppIDCol_Add(This,AppID,ppRef)	\
    (This)->lpVtbl -> Add(This,AppID,ppRef)

#define IExtractAppIDCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractAppIDCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractAppIDCol_Add_Proxy( 
    IExtractAppIDCol __RPC_FAR * This,
    /* [in] */ BSTR AppID,
    /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractAppIDCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractAppIDCol_get_Item_Proxy( 
    IExtractAppIDCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractAppIDInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractAppIDCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractAppIDCol_get_Count_Proxy( 
    IExtractAppIDCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractAppIDCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractAppIDCol_INTERFACE_DEFINED__ */


#ifndef __IExtractComClassCol_INTERFACE_DEFINED__
#define __IExtractComClassCol_INTERFACE_DEFINED__

/* interface IExtractComClassCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractComClassCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("26A89D3E-3A2E-4637-A28A-22B23342D593")
    IExtractComClassCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR CLSID,
            /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractComClassColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractComClassCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractComClassCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ BSTR CLSID,
            /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractComClassCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractComClassColVtbl;

    interface IExtractComClassCol
    {
        CONST_VTBL struct IExtractComClassColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractComClassCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractComClassCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractComClassCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractComClassCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractComClassCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractComClassCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractComClassCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractComClassCol_Add(This,CLSID,ppRef)	\
    (This)->lpVtbl -> Add(This,CLSID,ppRef)

#define IExtractComClassCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractComClassCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractComClassCol_Add_Proxy( 
    IExtractComClassCol __RPC_FAR * This,
    /* [in] */ BSTR CLSID,
    /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractComClassCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractComClassCol_get_Item_Proxy( 
    IExtractComClassCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractComClass __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractComClassCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractComClassCol_get_Count_Proxy( 
    IExtractComClassCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractComClassCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractComClassCol_INTERFACE_DEFINED__ */


#ifndef __IExtractProgIDCol_INTERFACE_DEFINED__
#define __IExtractProgIDCol_INTERFACE_DEFINED__

/* interface IExtractProgIDCol */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractProgIDCol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0BBCC11F-27E2-4870-B015-401E2A152CAE")
    IExtractProgIDCol : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractProgIDColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractProgIDCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractProgIDCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IExtractProgIDCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pCount);
        
        END_INTERFACE
    } IExtractProgIDColVtbl;

    interface IExtractProgIDCol
    {
        CONST_VTBL struct IExtractProgIDColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractProgIDCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractProgIDCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractProgIDCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractProgIDCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractProgIDCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractProgIDCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractProgIDCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractProgIDCol_Add(This,ProgID,ppRef)	\
    (This)->lpVtbl -> Add(This,ProgID,ppRef)

#define IExtractProgIDCol_get_Item(This,Key,ppRef)	\
    (This)->lpVtbl -> get_Item(This,Key,ppRef)

#define IExtractProgIDCol_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IExtractProgIDCol_Add_Proxy( 
    IExtractProgIDCol __RPC_FAR * This,
    /* [in] */ BSTR ProgID,
    /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractProgIDCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractProgIDCol_get_Item_Proxy( 
    IExtractProgIDCol __RPC_FAR * This,
    /* [in] */ VARIANT Key,
    /* [retval][out] */ IExtractProgIDInfo __RPC_FAR *__RPC_FAR *ppRef);


void __RPC_STUB IExtractProgIDCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IExtractProgIDCol_get_Count_Proxy( 
    IExtractProgIDCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pCount);


void __RPC_STUB IExtractProgIDCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractProgIDCol_INTERFACE_DEFINED__ */


#ifndef __IExtractComponent_INTERFACE_DEFINED__
#define __IExtractComponent_INTERFACE_DEFINED__

/* interface IExtractComponent */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IExtractComponent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("847830FB-A557-44DA-A48C-465E87DDE126")
    IExtractComponent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeyFile( 
            /* [defaultvalue][in] */ VARIANT_BOOL bRepackager,
            /* [retval][out] */ BSTR __RPC_FAR *pKeyFile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDestination) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TypeLibCollection( 
            /* [retval][out] */ IExtractTypeLibCol __RPC_FAR *__RPC_FAR *ppTypeLibColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ComClassCollection( 
            /* [retval][out] */ IExtractComClassCol __RPC_FAR *__RPC_FAR *ppComClassColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppInfoCollection( 
            /* [retval][out] */ IExtractAppIDCol __RPC_FAR *__RPC_FAR *ppAppInfoColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgIDCollection( 
            /* [retval][out] */ IExtractProgIDCol __RPC_FAR *__RPC_FAR *ppProgIDColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExtensionCol( 
            /* [retval][out] */ IExtractExtensionCol __RPC_FAR *__RPC_FAR *ppProgIDColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MIMECol( 
            /* [retval][out] */ IExtractMIMECol __RPC_FAR *__RPC_FAR *ppMIMEDColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMiscRegistryInfo( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ProxyValue( 
            /* [in] */ BSTR bstrProxyKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractComponentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExtractComponent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExtractComponent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExtractComponent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_KeyFile )( 
            IExtractComponent __RPC_FAR * This,
            /* [defaultvalue][in] */ VARIANT_BOOL bRepackager,
            /* [retval][out] */ BSTR __RPC_FAR *pKeyFile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Destination )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrDestination);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TypeLibCollection )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractTypeLibCol __RPC_FAR *__RPC_FAR *ppTypeLibColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ComClassCollection )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractComClassCol __RPC_FAR *__RPC_FAR *ppComClassColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AppInfoCollection )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractAppIDCol __RPC_FAR *__RPC_FAR *ppAppInfoColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProgIDCollection )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractProgIDCol __RPC_FAR *__RPC_FAR *ppProgIDColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtensionCol )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractExtensionCol __RPC_FAR *__RPC_FAR *ppProgIDColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MIMECol )( 
            IExtractComponent __RPC_FAR * This,
            /* [retval][out] */ IExtractMIMECol __RPC_FAR *__RPC_FAR *ppMIMEDColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddMiscRegistryInfo )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProxyValue )( 
            IExtractComponent __RPC_FAR * This,
            /* [in] */ BSTR bstrProxyKey);
        
        END_INTERFACE
    } IExtractComponentVtbl;

    interface IExtractComponent
    {
        CONST_VTBL struct IExtractComponentVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractComponent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractComponent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractComponent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractComponent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExtractComponent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExtractComponent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExtractComponent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExtractComponent_get_KeyFile(This,bRepackager,pKeyFile)	\
    (This)->lpVtbl -> get_KeyFile(This,bRepackager,pKeyFile)

#define IExtractComponent_get_Destination(This,pbstrDestination)	\
    (This)->lpVtbl -> get_Destination(This,pbstrDestination)

#define IExtractComponent_get_TypeLibCollection(This,ppTypeLibColl)	\
    (This)->lpVtbl -> get_TypeLibCollection(This,ppTypeLibColl)

#define IExtractComponent_get_ComClassCollection(This,ppComClassColl)	\
    (This)->lpVtbl -> get_ComClassCollection(This,ppComClassColl)

#define IExtractComponent_get_AppInfoCollection(This,ppAppInfoColl)	\
    (This)->lpVtbl -> get_AppInfoCollection(This,ppAppInfoColl)

#define IExtractComponent_get_ProgIDCollection(This,ppProgIDColl)	\
    (This)->lpVtbl -> get_ProgIDCollection(This,ppProgIDColl)

#define IExtractComponent_get_ExtensionCol(This,ppProgIDColl)	\
    (This)->lpVtbl -> get_ExtensionCol(This,ppProgIDColl)

#define IExtractComponent_get_MIMECol(This,ppMIMEDColl)	\
    (This)->lpVtbl -> get_MIMECol(This,ppMIMEDColl)

#define IExtractComponent_AddMiscRegistryInfo(This,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)	\
    (This)->lpVtbl -> AddMiscRegistryInfo(This,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)

#define IExtractComponent_put_ProxyValue(This,bstrProxyKey)	\
    (This)->lpVtbl -> put_ProxyValue(This,bstrProxyKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_KeyFile_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [defaultvalue][in] */ VARIANT_BOOL bRepackager,
    /* [retval][out] */ BSTR __RPC_FAR *pKeyFile);


void __RPC_STUB IExtractComponent_get_KeyFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_Destination_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrDestination);


void __RPC_STUB IExtractComponent_get_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_TypeLibCollection_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractTypeLibCol __RPC_FAR *__RPC_FAR *ppTypeLibColl);


void __RPC_STUB IExtractComponent_get_TypeLibCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_ComClassCollection_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractComClassCol __RPC_FAR *__RPC_FAR *ppComClassColl);


void __RPC_STUB IExtractComponent_get_ComClassCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_AppInfoCollection_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractAppIDCol __RPC_FAR *__RPC_FAR *ppAppInfoColl);


void __RPC_STUB IExtractComponent_get_AppInfoCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_ProgIDCollection_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractProgIDCol __RPC_FAR *__RPC_FAR *ppProgIDColl);


void __RPC_STUB IExtractComponent_get_ProgIDCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_ExtensionCol_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractExtensionCol __RPC_FAR *__RPC_FAR *ppProgIDColl);


void __RPC_STUB IExtractComponent_get_ExtensionCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExtractComponent_get_MIMECol_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [retval][out] */ IExtractMIMECol __RPC_FAR *__RPC_FAR *ppMIMEDColl);


void __RPC_STUB IExtractComponent_get_MIMECol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExtractComponent_AddMiscRegistryInfo_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IExtractComponent_AddMiscRegistryInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IExtractComponent_put_ProxyValue_Proxy( 
    IExtractComponent __RPC_FAR * This,
    /* [in] */ BSTR bstrProxyKey);


void __RPC_STUB IExtractComponent_put_ProxyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractComponent_INTERFACE_DEFINED__ */


#ifndef __IISXferIconResource_INTERFACE_DEFINED__
#define __IISXferIconResource_INTERFACE_DEFINED__

/* interface IISXferIconResource */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IISXferIconResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7134BE87-9B17-45EF-B8C8-B9C11B7B8EBB")
    IISXferIconResource : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSourceFile( 
            /* [in] */ BSTR bSourceFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSourceFile( 
            /* [out] */ VARIANT __RPC_FAR *pbSourceFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDestinationFile( 
            /* [in] */ BSTR bDestFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDestinationFile( 
            /* [out] */ VARIANT __RPC_FAR *pbDestFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CopyIconResource( 
            /* [in] */ VARIANT __RPC_FAR *nIconIndex,
            /* [out][in] */ VARIANT __RPC_FAR *nOutIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISXferIconResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISXferIconResource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISXferIconResource __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISXferIconResource __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSourceFile )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ BSTR bSourceFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceFile )( 
            IISXferIconResource __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pbSourceFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDestinationFile )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ BSTR bDestFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDestinationFile )( 
            IISXferIconResource __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pbDestFileName,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyIconResource )( 
            IISXferIconResource __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *nIconIndex,
            /* [out][in] */ VARIANT __RPC_FAR *nOutIndex,
            /* [retval][out] */ VARIANT __RPC_FAR *varResult);
        
        END_INTERFACE
    } IISXferIconResourceVtbl;

    interface IISXferIconResource
    {
        CONST_VTBL struct IISXferIconResourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISXferIconResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISXferIconResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISXferIconResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISXferIconResource_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISXferIconResource_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISXferIconResource_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISXferIconResource_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISXferIconResource_SetSourceFile(This,bSourceFileName,varResult)	\
    (This)->lpVtbl -> SetSourceFile(This,bSourceFileName,varResult)

#define IISXferIconResource_GetSourceFile(This,pbSourceFileName,varResult)	\
    (This)->lpVtbl -> GetSourceFile(This,pbSourceFileName,varResult)

#define IISXferIconResource_SetDestinationFile(This,bDestFileName,varResult)	\
    (This)->lpVtbl -> SetDestinationFile(This,bDestFileName,varResult)

#define IISXferIconResource_GetDestinationFile(This,pbDestFileName,varResult)	\
    (This)->lpVtbl -> GetDestinationFile(This,pbDestFileName,varResult)

#define IISXferIconResource_CopyIconResource(This,nIconIndex,nOutIndex,varResult)	\
    (This)->lpVtbl -> CopyIconResource(This,nIconIndex,nOutIndex,varResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IISXferIconResource_SetSourceFile_Proxy( 
    IISXferIconResource __RPC_FAR * This,
    /* [in] */ BSTR bSourceFileName,
    /* [retval][out] */ VARIANT __RPC_FAR *varResult);


void __RPC_STUB IISXferIconResource_SetSourceFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISXferIconResource_GetSourceFile_Proxy( 
    IISXferIconResource __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *pbSourceFileName,
    /* [retval][out] */ VARIANT __RPC_FAR *varResult);


void __RPC_STUB IISXferIconResource_GetSourceFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISXferIconResource_SetDestinationFile_Proxy( 
    IISXferIconResource __RPC_FAR * This,
    /* [in] */ BSTR bDestFileName,
    /* [retval][out] */ VARIANT __RPC_FAR *varResult);


void __RPC_STUB IISXferIconResource_SetDestinationFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISXferIconResource_GetDestinationFile_Proxy( 
    IISXferIconResource __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *pbDestFileName,
    /* [retval][out] */ VARIANT __RPC_FAR *varResult);


void __RPC_STUB IISXferIconResource_GetDestinationFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISXferIconResource_CopyIconResource_Proxy( 
    IISXferIconResource __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *nIconIndex,
    /* [out][in] */ VARIANT __RPC_FAR *nOutIndex,
    /* [retval][out] */ VARIANT __RPC_FAR *varResult);


void __RPC_STUB IISXferIconResource_CopyIconResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISXferIconResource_INTERFACE_DEFINED__ */


#ifndef __IServerInfoProgressEvent_INTERFACE_DEFINED__
#define __IServerInfoProgressEvent_INTERFACE_DEFINED__

/* interface IServerInfoProgressEvent */
/* [oleautomation][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerInfoProgressEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08D269D6-02CC-4DC2-ABD8-8075D68C9CF0")
    IServerInfoProgressEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProgressBarStatus( 
            /* [in] */ long lProgress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerInfoProgressEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IServerInfoProgressEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IServerInfoProgressEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IServerInfoProgressEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProgressBarStatus )( 
            IServerInfoProgressEvent __RPC_FAR * This,
            /* [in] */ long lProgress);
        
        END_INTERFACE
    } IServerInfoProgressEventVtbl;

    interface IServerInfoProgressEvent
    {
        CONST_VTBL struct IServerInfoProgressEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerInfoProgressEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerInfoProgressEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerInfoProgressEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerInfoProgressEvent_SetProgressBarStatus(This,lProgress)	\
    (This)->lpVtbl -> SetProgressBarStatus(This,lProgress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IServerInfoProgressEvent_SetProgressBarStatus_Proxy( 
    IServerInfoProgressEvent __RPC_FAR * This,
    /* [in] */ long lProgress);


void __RPC_STUB IServerInfoProgressEvent_SetProgressBarStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerInfoProgressEvent_INTERFACE_DEFINED__ */


#ifndef __IServerInfoProgressEvent2_INTERFACE_DEFINED__
#define __IServerInfoProgressEvent2_INTERFACE_DEFINED__

/* interface IServerInfoProgressEvent2 */
/* [oleautomation][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerInfoProgressEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A67C2414-3F22-4715-9C71-F37F67FD6949")
    IServerInfoProgressEvent2 : public IServerInfoProgressEvent
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LogStatus( 
            /* [in] */ BSTR sMsg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerInfoProgressEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IServerInfoProgressEvent2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IServerInfoProgressEvent2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IServerInfoProgressEvent2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProgressBarStatus )( 
            IServerInfoProgressEvent2 __RPC_FAR * This,
            /* [in] */ long lProgress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogStatus )( 
            IServerInfoProgressEvent2 __RPC_FAR * This,
            /* [in] */ BSTR sMsg);
        
        END_INTERFACE
    } IServerInfoProgressEvent2Vtbl;

    interface IServerInfoProgressEvent2
    {
        CONST_VTBL struct IServerInfoProgressEvent2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerInfoProgressEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerInfoProgressEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerInfoProgressEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerInfoProgressEvent2_SetProgressBarStatus(This,lProgress)	\
    (This)->lpVtbl -> SetProgressBarStatus(This,lProgress)


#define IServerInfoProgressEvent2_LogStatus(This,sMsg)	\
    (This)->lpVtbl -> LogStatus(This,sMsg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IServerInfoProgressEvent2_LogStatus_Proxy( 
    IServerInfoProgressEvent2 __RPC_FAR * This,
    /* [in] */ BSTR sMsg);


void __RPC_STUB IServerInfoProgressEvent2_LogStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerInfoProgressEvent2_INTERFACE_DEFINED__ */


#ifndef __IFileSys_INTERFACE_DEFINED__
#define __IFileSys_INTERFACE_DEFINED__

/* interface IFileSys */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileSys;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F35546C1-0784-4F86-984D-ED72BD2B2A74")
    IFileSys : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FileCopy( 
            /* [in] */ BSTR bstrSrcFile,
            /* [in] */ BSTR bstrTargetFile,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ LONG __RPC_FAR *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FileExists( 
            /* [in] */ BSTR bstrFile,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bExists) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDemo( 
            /* [in] */ BSTR bstrPath,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LogError( 
            /* [in] */ BSTR bstrMessage,
            /* [in] */ BSTR bstrUrl,
            /* [in] */ BSTR bstrLine) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsFileUnicode( 
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbIsUnicode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LogMessage( 
            BSTR bstrMessage,
            BSTR bstrFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileType( 
            /* [in] */ BSTR sFileName,
            /* [retval][out] */ EnumFileType __RPC_FAR *enumFileType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCPSupported( 
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bSupported) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCPInstalled( 
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bInstalled) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVxdVersionInfoSize( 
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ LONG __RPC_FAR *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVxdVersionInfo( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ LONG Len,
            /* [out] */ LONG __RPC_FAR *dwFileVersionMS,
            /* [out] */ LONG __RPC_FAR *dwFileVersionLS,
            /* [out] */ BSTR __RPC_FAR *bstrVersion,
            /* [out] */ VARIANT __RPC_FAR *pLanguage,
            /* [out] */ VARIANT __RPC_FAR *pCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetShortLongFilename( 
            /* [in] */ BSTR bstrFilename,
            /* [in] */ BSTR bstrLangID,
            /* [out] */ BSTR __RPC_FAR *bstrShortLongName,
            /* [retval][out] */ LONG __RPC_FAR *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileSysVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFileSys __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFileSys __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFileSys __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileCopy )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrSrcFile,
            /* [in] */ BSTR bstrTargetFile,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileExists )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrFile,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bExists);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDemo )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogError )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrMessage,
            /* [in] */ BSTR bstrUrl,
            /* [in] */ BSTR bstrLine);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsFileUnicode )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbIsUnicode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogMessage )( 
            IFileSys __RPC_FAR * This,
            BSTR bstrMessage,
            BSTR bstrFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileType )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [retval][out] */ EnumFileType __RPC_FAR *enumFileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsCPSupported )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bSupported);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsCPInstalled )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bInstalled);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVxdVersionInfoSize )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVxdVersionInfo )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ LONG Len,
            /* [out] */ LONG __RPC_FAR *dwFileVersionMS,
            /* [out] */ LONG __RPC_FAR *dwFileVersionLS,
            /* [out] */ BSTR __RPC_FAR *bstrVersion,
            /* [out] */ VARIANT __RPC_FAR *pLanguage,
            /* [out] */ VARIANT __RPC_FAR *pCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShortLongFilename )( 
            IFileSys __RPC_FAR * This,
            /* [in] */ BSTR bstrFilename,
            /* [in] */ BSTR bstrLangID,
            /* [out] */ BSTR __RPC_FAR *bstrShortLongName,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        END_INTERFACE
    } IFileSysVtbl;

    interface IFileSys
    {
        CONST_VTBL struct IFileSysVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileSys_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFileSys_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFileSys_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFileSys_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFileSys_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFileSys_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFileSys_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFileSys_FileCopy(This,bstrSrcFile,bstrTargetFile,bOverWrite,pResult)	\
    (This)->lpVtbl -> FileCopy(This,bstrSrcFile,bstrTargetFile,bOverWrite,pResult)

#define IFileSys_FileExists(This,bstrFile,bExists)	\
    (This)->lpVtbl -> FileExists(This,bstrFile,bExists)

#define IFileSys_ShowDemo(This,bstrPath,bstrFileName,vbSuccess)	\
    (This)->lpVtbl -> ShowDemo(This,bstrPath,bstrFileName,vbSuccess)

#define IFileSys_LogError(This,bstrMessage,bstrUrl,bstrLine)	\
    (This)->lpVtbl -> LogError(This,bstrMessage,bstrUrl,bstrLine)

#define IFileSys_IsFileUnicode(This,bstrFileName,vbIsUnicode)	\
    (This)->lpVtbl -> IsFileUnicode(This,bstrFileName,vbIsUnicode)

#define IFileSys_LogMessage(This,bstrMessage,bstrFileName)	\
    (This)->lpVtbl -> LogMessage(This,bstrMessage,bstrFileName)

#define IFileSys_FileType(This,sFileName,enumFileType)	\
    (This)->lpVtbl -> FileType(This,sFileName,enumFileType)

#define IFileSys_IsCPSupported(This,sCodePage,bSupported)	\
    (This)->lpVtbl -> IsCPSupported(This,sCodePage,bSupported)

#define IFileSys_IsCPInstalled(This,sCodePage,bInstalled)	\
    (This)->lpVtbl -> IsCPInstalled(This,sCodePage,bInstalled)

#define IFileSys_GetVxdVersionInfoSize(This,bstrFileName,pResult)	\
    (This)->lpVtbl -> GetVxdVersionInfoSize(This,bstrFileName,pResult)

#define IFileSys_GetVxdVersionInfo(This,bstrFileName,Len,dwFileVersionMS,dwFileVersionLS,bstrVersion,pLanguage,pCodePage,vbSuccess)	\
    (This)->lpVtbl -> GetVxdVersionInfo(This,bstrFileName,Len,dwFileVersionMS,dwFileVersionLS,bstrVersion,pLanguage,pCodePage,vbSuccess)

#define IFileSys_GetShortLongFilename(This,bstrFilename,bstrLangID,bstrShortLongName,pResult)	\
    (This)->lpVtbl -> GetShortLongFilename(This,bstrFilename,bstrLangID,bstrShortLongName,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_FileCopy_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrSrcFile,
    /* [in] */ BSTR bstrTargetFile,
    /* [in] */ VARIANT_BOOL bOverWrite,
    /* [retval][out] */ LONG __RPC_FAR *pResult);


void __RPC_STUB IFileSys_FileCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_FileExists_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrFile,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bExists);


void __RPC_STUB IFileSys_FileExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_ShowDemo_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrPath,
    /* [in] */ BSTR bstrFileName,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);


void __RPC_STUB IFileSys_ShowDemo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_LogError_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrMessage,
    /* [in] */ BSTR bstrUrl,
    /* [in] */ BSTR bstrLine);


void __RPC_STUB IFileSys_LogError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_IsFileUnicode_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrFileName,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbIsUnicode);


void __RPC_STUB IFileSys_IsFileUnicode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFileSys_LogMessage_Proxy( 
    IFileSys __RPC_FAR * This,
    BSTR bstrMessage,
    BSTR bstrFileName);


void __RPC_STUB IFileSys_LogMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFileSys_FileType_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR sFileName,
    /* [retval][out] */ EnumFileType __RPC_FAR *enumFileType);


void __RPC_STUB IFileSys_FileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFileSys_IsCPSupported_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR sCodePage,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bSupported);


void __RPC_STUB IFileSys_IsCPSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFileSys_IsCPInstalled_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR sCodePage,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bInstalled);


void __RPC_STUB IFileSys_IsCPInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_GetVxdVersionInfoSize_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrFileName,
    /* [retval][out] */ LONG __RPC_FAR *pResult);


void __RPC_STUB IFileSys_GetVxdVersionInfoSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_GetVxdVersionInfo_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ LONG Len,
    /* [out] */ LONG __RPC_FAR *dwFileVersionMS,
    /* [out] */ LONG __RPC_FAR *dwFileVersionLS,
    /* [out] */ BSTR __RPC_FAR *bstrVersion,
    /* [out] */ VARIANT __RPC_FAR *pLanguage,
    /* [out] */ VARIANT __RPC_FAR *pCodePage,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);


void __RPC_STUB IFileSys_GetVxdVersionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFileSys_GetShortLongFilename_Proxy( 
    IFileSys __RPC_FAR * This,
    /* [in] */ BSTR bstrFilename,
    /* [in] */ BSTR bstrLangID,
    /* [out] */ BSTR __RPC_FAR *bstrShortLongName,
    /* [retval][out] */ LONG __RPC_FAR *pResult);


void __RPC_STUB IFileSys_GetShortLongFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFileSys_INTERFACE_DEFINED__ */


#ifndef ___Collection_INTERFACE_DEFINED__
#define ___Collection_INTERFACE_DEFINED__

/* interface _Collection */
/* [object][oleautomation][dual][hidden][helpcontext][uuid] */ 


EXTERN_C const IID IID__Collection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D7686FA-9F85-45F1-8EE4-C79D3FB91830")
    _Collection : public IDispatch
    {
    public:
        virtual /* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT __RPC_FAR *Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarRet) = 0;
        
        virtual /* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT __RPC_FAR *Item,
            /* [optional][in] */ VARIANT __RPC_FAR *Key,
            /* [optional][in] */ VARIANT __RPC_FAR *Before,
            /* [optional][in] */ VARIANT __RPC_FAR *After) = 0;
        
        virtual /* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long __RPC_FAR *pi4) = 0;
        
        virtual /* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT __RPC_FAR *Index) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _CollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _Collection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _Collection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _Collection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _Collection __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _Collection __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _Collection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _Collection __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            _Collection __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *Index,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarRet);
        
        /* [helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            _Collection __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *Item,
            /* [optional][in] */ VARIANT __RPC_FAR *Key,
            /* [optional][in] */ VARIANT __RPC_FAR *Before,
            /* [optional][in] */ VARIANT __RPC_FAR *After);
        
        /* [helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Count )( 
            _Collection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pi4);
        
        /* [helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            _Collection __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *Index);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            _Collection __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);
        
        END_INTERFACE
    } _CollectionVtbl;

    interface _Collection
    {
        CONST_VTBL struct _CollectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Collection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _Collection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _Collection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _Collection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _Collection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _Collection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _Collection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _Collection_Item(This,Index,pvarRet)	\
    (This)->lpVtbl -> Item(This,Index,pvarRet)

#define _Collection_Add(This,Item,Key,Before,After)	\
    (This)->lpVtbl -> Add(This,Item,Key,Before,After)

#define _Collection_Count(This,pi4)	\
    (This)->lpVtbl -> Count(This,pi4)

#define _Collection_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define _Collection__NewEnum(This,ppunk)	\
    (This)->lpVtbl -> _NewEnum(This,ppunk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE _Collection_Item_Proxy( 
    _Collection __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *Index,
    /* [retval][out] */ VARIANT __RPC_FAR *pvarRet);


void __RPC_STUB _Collection_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE _Collection_Add_Proxy( 
    _Collection __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *Item,
    /* [optional][in] */ VARIANT __RPC_FAR *Key,
    /* [optional][in] */ VARIANT __RPC_FAR *Before,
    /* [optional][in] */ VARIANT __RPC_FAR *After);


void __RPC_STUB _Collection_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE _Collection_Count_Proxy( 
    _Collection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pi4);


void __RPC_STUB _Collection_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][id] */ HRESULT STDMETHODCALLTYPE _Collection_Remove_Proxy( 
    _Collection __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *Index);


void __RPC_STUB _Collection_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _Collection__NewEnum_Proxy( 
    _Collection __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);


void __RPC_STUB _Collection__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___Collection_INTERFACE_DEFINED__ */


#ifndef __IRegistry_INTERFACE_DEFINED__
#define __IRegistry_INTERFACE_DEFINED__

/* interface IRegistry */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRegistry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0094C0C2-AA06-4A4A-8CF1-A6B011AD9F03")
    IRegistry : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegAddValue( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [in] */ ERegistryDataTypes nType,
            /* [in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegReadValue( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [in] */ ERegistryDataTypes nType,
            /* [out][in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegQueryKey( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ERegistryQueryTypes nQueryType,
            /* [out][in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegDeleteValue( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegSoftDeleteRegValue( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegSetExtractComponent( 
            /* [in] */ IExtractComponent __RPC_FAR *pExtractComponent,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegReadType( 
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [out][in] */ long __RPC_FAR *lType,
            /* [retval][out] */ long __RPC_FAR *lResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRegistryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRegistry __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRegistry __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRegistry __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegAddValue )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [in] */ ERegistryDataTypes nType,
            /* [in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegReadValue )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [in] */ ERegistryDataTypes nType,
            /* [out][in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegQueryKey )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ERegistryQueryTypes nQueryType,
            /* [out][in] */ VARIANT __RPC_FAR *pValue,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegDeleteValue )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegSoftDeleteRegValue )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegSetExtractComponent )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ IExtractComponent __RPC_FAR *pExtractComponent,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegReadType )( 
            IRegistry __RPC_FAR * This,
            /* [in] */ ERegistryHives hROOT,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrValueName,
            /* [out][in] */ long __RPC_FAR *lType,
            /* [retval][out] */ long __RPC_FAR *lResult);
        
        END_INTERFACE
    } IRegistryVtbl;

    interface IRegistry
    {
        CONST_VTBL struct IRegistryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRegistry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRegistry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRegistry_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRegistry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRegistry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRegistry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRegistry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRegistry_RegAddValue(This,hROOT,bstrKey,bstrValueName,nType,pValue,lResult)	\
    (This)->lpVtbl -> RegAddValue(This,hROOT,bstrKey,bstrValueName,nType,pValue,lResult)

#define IRegistry_RegReadValue(This,hROOT,bstrKey,bstrValueName,nType,pValue,lResult)	\
    (This)->lpVtbl -> RegReadValue(This,hROOT,bstrKey,bstrValueName,nType,pValue,lResult)

#define IRegistry_RegQueryKey(This,hROOT,bstrKey,nQueryType,pValue,lResult)	\
    (This)->lpVtbl -> RegQueryKey(This,hROOT,bstrKey,nQueryType,pValue,lResult)

#define IRegistry_RegDeleteValue(This,hROOT,bstrKey,bstrValueName,lResult)	\
    (This)->lpVtbl -> RegDeleteValue(This,hROOT,bstrKey,bstrValueName,lResult)

#define IRegistry_RegSoftDeleteRegValue(This,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)	\
    (This)->lpVtbl -> RegSoftDeleteRegValue(This,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)

#define IRegistry_RegSetExtractComponent(This,pExtractComponent,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)	\
    (This)->lpVtbl -> RegSetExtractComponent(This,pExtractComponent,hROOT,bstrKey,bstrValueName,bDeleteAllValues,lResult)

#define IRegistry_RegReadType(This,hROOT,bstrKey,bstrValueName,lType,lResult)	\
    (This)->lpVtbl -> RegReadType(This,hROOT,bstrKey,bstrValueName,lType,lResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegAddValue_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [in] */ ERegistryDataTypes nType,
    /* [in] */ VARIANT __RPC_FAR *pValue,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegAddValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegReadValue_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [in] */ ERegistryDataTypes nType,
    /* [out][in] */ VARIANT __RPC_FAR *pValue,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegReadValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegQueryKey_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ ERegistryQueryTypes nQueryType,
    /* [out][in] */ VARIANT __RPC_FAR *pValue,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegQueryKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegDeleteValue_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegDeleteValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegSoftDeleteRegValue_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegSoftDeleteRegValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegSetExtractComponent_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ IExtractComponent __RPC_FAR *pExtractComponent,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [defaultvalue][in] */ VARIANT_BOOL bDeleteAllValues,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegSetExtractComponent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRegistry_RegReadType_Proxy( 
    IRegistry __RPC_FAR * This,
    /* [in] */ ERegistryHives hROOT,
    /* [in] */ BSTR bstrKey,
    /* [in] */ BSTR bstrValueName,
    /* [out][in] */ long __RPC_FAR *lType,
    /* [retval][out] */ long __RPC_FAR *lResult);


void __RPC_STUB IRegistry_RegReadType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRegistry_INTERFACE_DEFINED__ */


#ifndef __IGuid_INTERFACE_DEFINED__
#define __IGuid_INTERFACE_DEFINED__

/* interface IGuid */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGuid;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C701E93-8D26-40B5-85FE-AD6CC98BC237")
    IGuid : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateGuid( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrGuid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGuidVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGuid __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGuid __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGuid __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGuid __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGuid __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGuid __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGuid __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateGuid )( 
            IGuid __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrGuid);
        
        END_INTERFACE
    } IGuidVtbl;

    interface IGuid
    {
        CONST_VTBL struct IGuidVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGuid_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGuid_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGuid_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGuid_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGuid_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGuid_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGuid_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGuid_CreateGuid(This,pbstrGuid)	\
    (This)->lpVtbl -> CreateGuid(This,pbstrGuid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGuid_CreateGuid_Proxy( 
    IGuid __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrGuid);


void __RPC_STUB IGuid_CreateGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGuid_INTERFACE_DEFINED__ */


#ifndef __ISearchReplace_INTERFACE_DEFINED__
#define __ISearchReplace_INTERFACE_DEFINED__

/* interface ISearchReplace */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISearchReplace;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E313A43C-2540-468F-878E-828828B25777")
    ISearchReplace : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SearchAndReplace( 
            BSTR bSourceFile,
            BSTR bDestFile,
            BSTR bSearchText,
            BSTR bReplaceText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultPath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultPath( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISearchReplaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISearchReplace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISearchReplace __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISearchReplace __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISearchReplace __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISearchReplace __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISearchReplace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISearchReplace __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SearchAndReplace )( 
            ISearchReplace __RPC_FAR * This,
            BSTR bSourceFile,
            BSTR bDestFile,
            BSTR bSearchText,
            BSTR bReplaceText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultPath )( 
            ISearchReplace __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultPath )( 
            ISearchReplace __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ISearchReplaceVtbl;

    interface ISearchReplace
    {
        CONST_VTBL struct ISearchReplaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchReplace_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISearchReplace_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISearchReplace_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISearchReplace_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISearchReplace_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISearchReplace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISearchReplace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISearchReplace_SearchAndReplace(This,bSourceFile,bDestFile,bSearchText,bReplaceText)	\
    (This)->lpVtbl -> SearchAndReplace(This,bSourceFile,bDestFile,bSearchText,bReplaceText)

#define ISearchReplace_get_DefaultPath(This,pVal)	\
    (This)->lpVtbl -> get_DefaultPath(This,pVal)

#define ISearchReplace_put_DefaultPath(This,newVal)	\
    (This)->lpVtbl -> put_DefaultPath(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISearchReplace_SearchAndReplace_Proxy( 
    ISearchReplace __RPC_FAR * This,
    BSTR bSourceFile,
    BSTR bDestFile,
    BSTR bSearchText,
    BSTR bReplaceText);


void __RPC_STUB ISearchReplace_SearchAndReplace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISearchReplace_get_DefaultPath_Proxy( 
    ISearchReplace __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISearchReplace_get_DefaultPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISearchReplace_put_DefaultPath_Proxy( 
    ISearchReplace __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISearchReplace_put_DefaultPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISearchReplace_INTERFACE_DEFINED__ */


#ifndef __IServerInfo_INTERFACE_DEFINED__
#define __IServerInfo_INTERFACE_DEFINED__

/* interface IServerInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7E53BC4-B50E-4F3B-A1FE-7498CA4A5BC2")
    IServerInfo : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetServer( 
            /* [in] */ long lCElems,
            /* [size_is][in] */ IDispatch __RPC_FAR *__RPC_FAR pComponents[  ],
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemapRegistry( 
            /* [retval][out] */ long __RPC_FAR *plResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnmapRegistry( 
            /* [retval][out] */ long __RPC_FAR *plResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CleanupRegistry( 
            /* [retval][out] */ long __RPC_FAR *plResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsMappingAvailable( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bMapping) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AllowMapping( 
            /* [in] */ VARIANT_BOOL __RPC_FAR *bMapping) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetServerVB( 
            /* [in] */ _Collection __RPC_FAR *pCollection,
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ComExtractCommandLine( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ComExtractCommandLine( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IServerInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IServerInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IServerInfo __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServer )( 
            IServerInfo __RPC_FAR * This,
            /* [in] */ long lCElems,
            /* [size_is][in] */ IDispatch __RPC_FAR *__RPC_FAR pComponents[  ],
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemapRegistry )( 
            IServerInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnmapRegistry )( 
            IServerInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CleanupRegistry )( 
            IServerInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsMappingAvailable )( 
            IServerInfo __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllowMapping )( 
            IServerInfo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL __RPC_FAR *bMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServerVB )( 
            IServerInfo __RPC_FAR * This,
            /* [in] */ _Collection __RPC_FAR *pCollection,
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ComExtractCommandLine )( 
            IServerInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ComExtractCommandLine )( 
            IServerInfo __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IServerInfoVtbl;

    interface IServerInfo
    {
        CONST_VTBL struct IServerInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerInfo_SetServer(This,lCElems,pComponents,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)	\
    (This)->lpVtbl -> SetServer(This,lCElems,pComponents,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)

#define IServerInfo_RemapRegistry(This,plResult)	\
    (This)->lpVtbl -> RemapRegistry(This,plResult)

#define IServerInfo_UnmapRegistry(This,plResult)	\
    (This)->lpVtbl -> UnmapRegistry(This,plResult)

#define IServerInfo_CleanupRegistry(This,plResult)	\
    (This)->lpVtbl -> CleanupRegistry(This,plResult)

#define IServerInfo_IsMappingAvailable(This,bMapping)	\
    (This)->lpVtbl -> IsMappingAvailable(This,bMapping)

#define IServerInfo_AllowMapping(This,bMapping)	\
    (This)->lpVtbl -> AllowMapping(This,bMapping)

#define IServerInfo_SetServerVB(This,pCollection,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)	\
    (This)->lpVtbl -> SetServerVB(This,pCollection,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)

#define IServerInfo_get_ComExtractCommandLine(This,pVal)	\
    (This)->lpVtbl -> get_ComExtractCommandLine(This,pVal)

#define IServerInfo_put_ComExtractCommandLine(This,newVal)	\
    (This)->lpVtbl -> put_ComExtractCommandLine(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_SetServer_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [in] */ long lCElems,
    /* [size_is][in] */ IDispatch __RPC_FAR *__RPC_FAR pComponents[  ],
    IRegistry __RPC_FAR *pRegistry,
    /* [in] */ VARIANT_BOOL bRepackager,
    /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
    /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
    /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
    /* [retval][out] */ long __RPC_FAR *plResult);


void __RPC_STUB IServerInfo_SetServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_RemapRegistry_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plResult);


void __RPC_STUB IServerInfo_RemapRegistry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_UnmapRegistry_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plResult);


void __RPC_STUB IServerInfo_UnmapRegistry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_CleanupRegistry_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plResult);


void __RPC_STUB IServerInfo_CleanupRegistry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_IsMappingAvailable_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bMapping);


void __RPC_STUB IServerInfo_IsMappingAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_AllowMapping_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL __RPC_FAR *bMapping);


void __RPC_STUB IServerInfo_AllowMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IServerInfo_SetServerVB_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [in] */ _Collection __RPC_FAR *pCollection,
    IRegistry __RPC_FAR *pRegistry,
    /* [in] */ VARIANT_BOOL bRepackager,
    /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
    /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
    /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
    /* [retval][out] */ long __RPC_FAR *plResult);


void __RPC_STUB IServerInfo_SetServerVB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IServerInfo_get_ComExtractCommandLine_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IServerInfo_get_ComExtractCommandLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IServerInfo_put_ComExtractCommandLine_Proxy( 
    IServerInfo __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IServerInfo_put_ComExtractCommandLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerInfo_INTERFACE_DEFINED__ */


#ifndef __IServerInfoIronwood_INTERFACE_DEFINED__
#define __IServerInfoIronwood_INTERFACE_DEFINED__

/* interface IServerInfoIronwood */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IServerInfoIronwood;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EE7F4959-B042-4aee-9784-A76D33EEB369")
    IServerInfoIronwood : public IServerInfo
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForceTypelibsToTypelibTable( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bForce) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForceTypelibsToTypelibTable( 
            /* [in] */ VARIANT_BOOL bForce) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerInfoIronwoodVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IServerInfoIronwood __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IServerInfoIronwood __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServer )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ long lCElems,
            /* [size_is][in] */ IDispatch __RPC_FAR *__RPC_FAR pComponents[  ],
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemapRegistry )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnmapRegistry )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CleanupRegistry )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsMappingAvailable )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllowMapping )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL __RPC_FAR *bMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServerVB )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ _Collection __RPC_FAR *pCollection,
            IRegistry __RPC_FAR *pRegistry,
            /* [in] */ VARIANT_BOOL bRepackager,
            /* [defaultvalue][in] */ VARIANT_BOOL bRegisterServer,
            /* [defaultvalue][in] */ VARIANT_BOOL bUnregisterServer,
            /* [defaultvalue][optional][in] */ IServerInfoProgressEvent __RPC_FAR *pServerInfoProgress,
            /* [retval][out] */ long __RPC_FAR *plResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ComExtractCommandLine )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ComExtractCommandLine )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForceTypelibsToTypelibTable )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bForce);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForceTypelibsToTypelibTable )( 
            IServerInfoIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL bForce);
        
        END_INTERFACE
    } IServerInfoIronwoodVtbl;

    interface IServerInfoIronwood
    {
        CONST_VTBL struct IServerInfoIronwoodVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerInfoIronwood_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerInfoIronwood_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerInfoIronwood_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerInfoIronwood_SetServer(This,lCElems,pComponents,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)	\
    (This)->lpVtbl -> SetServer(This,lCElems,pComponents,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)

#define IServerInfoIronwood_RemapRegistry(This,plResult)	\
    (This)->lpVtbl -> RemapRegistry(This,plResult)

#define IServerInfoIronwood_UnmapRegistry(This,plResult)	\
    (This)->lpVtbl -> UnmapRegistry(This,plResult)

#define IServerInfoIronwood_CleanupRegistry(This,plResult)	\
    (This)->lpVtbl -> CleanupRegistry(This,plResult)

#define IServerInfoIronwood_IsMappingAvailable(This,bMapping)	\
    (This)->lpVtbl -> IsMappingAvailable(This,bMapping)

#define IServerInfoIronwood_AllowMapping(This,bMapping)	\
    (This)->lpVtbl -> AllowMapping(This,bMapping)

#define IServerInfoIronwood_SetServerVB(This,pCollection,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)	\
    (This)->lpVtbl -> SetServerVB(This,pCollection,pRegistry,bRepackager,bRegisterServer,bUnregisterServer,pServerInfoProgress,plResult)

#define IServerInfoIronwood_get_ComExtractCommandLine(This,pVal)	\
    (This)->lpVtbl -> get_ComExtractCommandLine(This,pVal)

#define IServerInfoIronwood_put_ComExtractCommandLine(This,newVal)	\
    (This)->lpVtbl -> put_ComExtractCommandLine(This,newVal)


#define IServerInfoIronwood_get_ForceTypelibsToTypelibTable(This,bForce)	\
    (This)->lpVtbl -> get_ForceTypelibsToTypelibTable(This,bForce)

#define IServerInfoIronwood_put_ForceTypelibsToTypelibTable(This,bForce)	\
    (This)->lpVtbl -> put_ForceTypelibsToTypelibTable(This,bForce)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IServerInfoIronwood_get_ForceTypelibsToTypelibTable_Proxy( 
    IServerInfoIronwood __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bForce);


void __RPC_STUB IServerInfoIronwood_get_ForceTypelibsToTypelibTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IServerInfoIronwood_put_ForceTypelibsToTypelibTable_Proxy( 
    IServerInfoIronwood __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL bForce);


void __RPC_STUB IServerInfoIronwood_put_ForceTypelibsToTypelibTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServerInfoIronwood_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ISUtil_0283 */
/* [local] */ 

typedef /* [public][public][helpstring][uuid] */ 
enum __MIDL___MIDL_itf_ISUtil_0283_0001
    {	clsInprocServer	= 0x1,
	clsInprocServer32	= 0x2,
	clsLocalServer	= 0x4,
	clsLocalServer32	= 0x8
    }	ExecContext;



extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0283_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0283_v0_0_s_ifspec;

#ifndef __IPropertyHeader_INTERFACE_DEFINED__
#define __IPropertyHeader_INTERFACE_DEFINED__

/* interface IPropertyHeader */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPropertyHeader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93E4F355-CD1A-447B-BD91-364ECFFC6093")
    IPropertyHeader : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PropertyName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyClass( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PropertyClass( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyHeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPropertyHeader __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPropertyHeader __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPropertyHeader __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertyName )( 
            IPropertyHeader __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PropertyName )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertyClass )( 
            IPropertyHeader __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PropertyClass )( 
            IPropertyHeader __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IPropertyHeaderVtbl;

    interface IPropertyHeader
    {
        CONST_VTBL struct IPropertyHeaderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyHeader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyHeader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyHeader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyHeader_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPropertyHeader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPropertyHeader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPropertyHeader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPropertyHeader_get_PropertyName(This,pVal)	\
    (This)->lpVtbl -> get_PropertyName(This,pVal)

#define IPropertyHeader_put_PropertyName(This,newVal)	\
    (This)->lpVtbl -> put_PropertyName(This,newVal)

#define IPropertyHeader_get_PropertyClass(This,pVal)	\
    (This)->lpVtbl -> get_PropertyClass(This,pVal)

#define IPropertyHeader_put_PropertyClass(This,newVal)	\
    (This)->lpVtbl -> put_PropertyClass(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPropertyHeader_get_PropertyName_Proxy( 
    IPropertyHeader __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPropertyHeader_get_PropertyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPropertyHeader_put_PropertyName_Proxy( 
    IPropertyHeader __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPropertyHeader_put_PropertyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPropertyHeader_get_PropertyClass_Proxy( 
    IPropertyHeader __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPropertyHeader_get_PropertyClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPropertyHeader_put_PropertyClass_Proxy( 
    IPropertyHeader __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPropertyHeader_put_PropertyClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropertyHeader_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ISUtil_0284 */
/* [local] */ 

typedef /* [helpstring][uuid] */ 
enum EEncryptAlgorithm
    {	algo1	= 0
    }	EEncryptAlgorithm;



extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0284_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0284_v0_0_s_ifspec;

#ifndef __IEncryptor_INTERFACE_DEFINED__
#define __IEncryptor_INTERFACE_DEFINED__

/* interface IEncryptor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEncryptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6205919A-931D-4947-A656-8C7057D1DC1B")
    IEncryptor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ EEncryptAlgorithm eeaType,
            /* [in] */ BSTR sInput,
            /* [out] */ BSTR __RPC_FAR *sOutput) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEncryptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEncryptor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEncryptor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEncryptor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEncryptor __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEncryptor __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEncryptor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEncryptor __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Encrypt )( 
            IEncryptor __RPC_FAR * This,
            /* [in] */ EEncryptAlgorithm eeaType,
            /* [in] */ BSTR sInput,
            /* [out] */ BSTR __RPC_FAR *sOutput);
        
        END_INTERFACE
    } IEncryptorVtbl;

    interface IEncryptor
    {
        CONST_VTBL struct IEncryptorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEncryptor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEncryptor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEncryptor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEncryptor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEncryptor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEncryptor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEncryptor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEncryptor_Encrypt(This,eeaType,sInput,sOutput)	\
    (This)->lpVtbl -> Encrypt(This,eeaType,sInput,sOutput)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEncryptor_Encrypt_Proxy( 
    IEncryptor __RPC_FAR * This,
    /* [in] */ EEncryptAlgorithm eeaType,
    /* [in] */ BSTR sInput,
    /* [out] */ BSTR __RPC_FAR *sOutput);


void __RPC_STUB IEncryptor_Encrypt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEncryptor_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ISUtil_0285 */
/* [local] */ 


typedef /* [uuid] */ struct  SignCodeOption
    {
    BSTR sFullPathSignCode;
    BSTR sSPC;
    BSTR sPVK;
    BSTR sTxtName;
    BSTR sURL;
    BSTR sTimeStampServer;
    BSTR sPassword;
    }	SignCodeOption;



extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0285_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0285_v0_0_s_ifspec;

#ifndef __ISignCodeEvent_INTERFACE_DEFINED__
#define __ISignCodeEvent_INTERFACE_DEFINED__

/* interface ISignCodeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISignCodeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4DC0AF07-D1DE-45AD-8475-557FC58F46E8")
    ISignCodeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OutPut( 
            /* [in] */ BSTR sOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Finished( 
            /* [in] */ long lRetCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISignCodeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISignCodeEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISignCodeEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutPut )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ BSTR sOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Finished )( 
            ISignCodeEvent __RPC_FAR * This,
            /* [in] */ long lRetCode);
        
        END_INTERFACE
    } ISignCodeEventVtbl;

    interface ISignCodeEvent
    {
        CONST_VTBL struct ISignCodeEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISignCodeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISignCodeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISignCodeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISignCodeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISignCodeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISignCodeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISignCodeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISignCodeEvent_OutPut(This,sOutput)	\
    (This)->lpVtbl -> OutPut(This,sOutput)

#define ISignCodeEvent_Finished(This,lRetCode)	\
    (This)->lpVtbl -> Finished(This,lRetCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISignCodeEvent_OutPut_Proxy( 
    ISignCodeEvent __RPC_FAR * This,
    /* [in] */ BSTR sOutput);


void __RPC_STUB ISignCodeEvent_OutPut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISignCodeEvent_Finished_Proxy( 
    ISignCodeEvent __RPC_FAR * This,
    /* [in] */ long lRetCode);


void __RPC_STUB ISignCodeEvent_Finished_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISignCodeEvent_INTERFACE_DEFINED__ */


#ifndef __ISignCode_INTERFACE_DEFINED__
#define __ISignCode_INTERFACE_DEFINED__

/* interface ISignCode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISignCode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5A7620F-6BB7-4A95-9F08-572EA28019D5")
    ISignCode : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR sFullName,
            /* [in] */ SignCodeOption __RPC_FAR *scoOption,
            /* [in] */ ISignCodeEvent __RPC_FAR *pCallBack) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISignCodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISignCode __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISignCode __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISignCode __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISignCode __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISignCode __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISignCode __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISignCode __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Sign )( 
            ISignCode __RPC_FAR * This,
            /* [in] */ BSTR sFullName,
            /* [in] */ SignCodeOption __RPC_FAR *scoOption,
            /* [in] */ ISignCodeEvent __RPC_FAR *pCallBack);
        
        END_INTERFACE
    } ISignCodeVtbl;

    interface ISignCode
    {
        CONST_VTBL struct ISignCodeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISignCode_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISignCode_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISignCode_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISignCode_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISignCode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISignCode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISignCode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISignCode_Sign(This,sFullName,scoOption,pCallBack)	\
    (This)->lpVtbl -> Sign(This,sFullName,scoOption,pCallBack)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISignCode_Sign_Proxy( 
    ISignCode __RPC_FAR * This,
    /* [in] */ BSTR sFullName,
    /* [in] */ SignCodeOption __RPC_FAR *scoOption,
    /* [in] */ ISignCodeEvent __RPC_FAR *pCallBack);


void __RPC_STUB ISignCode_Sign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISignCode_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ISUtil_0287 */
/* [local] */ 

typedef /* [uuid] */ struct  StampVerOption
    {
    BSTR sCompanyName;
    BSTR sProductName;
    BSTR sProductAndFileVer;
    BSTR sDescription;
    BSTR sCopyRight;
    DWORD dwLanguage;
    }	StampVerOption;



extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0287_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISUtil_0287_v0_0_s_ifspec;

#ifndef __IStampVersion_INTERFACE_DEFINED__
#define __IStampVersion_INTERFACE_DEFINED__

/* interface IStampVersion */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStampVersion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D484A800-40FA-4D26-8112-6CDB5788BCAE")
    IStampVersion : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stamp( 
            /* [in] */ BSTR sFile2Stamp,
            /* [in] */ StampVerOption __RPC_FAR *svoOption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStampVersionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStampVersion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStampVersion __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStampVersion __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStampVersion __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStampVersion __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStampVersion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStampVersion __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stamp )( 
            IStampVersion __RPC_FAR * This,
            /* [in] */ BSTR sFile2Stamp,
            /* [in] */ StampVerOption __RPC_FAR *svoOption);
        
        END_INTERFACE
    } IStampVersionVtbl;

    interface IStampVersion
    {
        CONST_VTBL struct IStampVersionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStampVersion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStampVersion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStampVersion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStampVersion_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStampVersion_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStampVersion_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStampVersion_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStampVersion_Stamp(This,sFile2Stamp,svoOption)	\
    (This)->lpVtbl -> Stamp(This,sFile2Stamp,svoOption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStampVersion_Stamp_Proxy( 
    IStampVersion __RPC_FAR * This,
    /* [in] */ BSTR sFile2Stamp,
    /* [in] */ StampVerOption __RPC_FAR *svoOption);


void __RPC_STUB IStampVersion_Stamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStampVersion_INTERFACE_DEFINED__ */



#ifndef __ISUtilityLib_LIBRARY_DEFINED__
#define __ISUtilityLib_LIBRARY_DEFINED__

/* library ISUtilityLib */
/* [version][helpstring][uuid] */ 


EXTERN_C const IID LIBID_ISUtilityLib;

#ifndef __IProgressNeptune_INTERFACE_DEFINED__
#define __IProgressNeptune_INTERFACE_DEFINED__

/* interface IProgressNeptune */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IProgressNeptune;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F992177D-7A34-44FD-B522-47200B404DCF")
    IProgressNeptune : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LogStatus( 
            /* [in] */ BSTR sMsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProgressBarStatus( 
            /* [in] */ long lProgress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProgressNeptuneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IProgressNeptune __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IProgressNeptune __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IProgressNeptune __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogStatus )( 
            IProgressNeptune __RPC_FAR * This,
            /* [in] */ BSTR sMsg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProgressBarStatus )( 
            IProgressNeptune __RPC_FAR * This,
            /* [in] */ long lProgress);
        
        END_INTERFACE
    } IProgressNeptuneVtbl;

    interface IProgressNeptune
    {
        CONST_VTBL struct IProgressNeptuneVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProgressNeptune_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProgressNeptune_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProgressNeptune_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProgressNeptune_LogStatus(This,sMsg)	\
    (This)->lpVtbl -> LogStatus(This,sMsg)

#define IProgressNeptune_SetProgressBarStatus(This,lProgress)	\
    (This)->lpVtbl -> SetProgressBarStatus(This,lProgress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IProgressNeptune_LogStatus_Proxy( 
    IProgressNeptune __RPC_FAR * This,
    /* [in] */ BSTR sMsg);


void __RPC_STUB IProgressNeptune_LogStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProgressNeptune_SetProgressBarStatus_Proxy( 
    IProgressNeptune __RPC_FAR * This,
    /* [in] */ long lProgress);


void __RPC_STUB IProgressNeptune_SetProgressBarStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProgressNeptune_INTERFACE_DEFINED__ */


#ifndef __IFileSysNeptune_INTERFACE_DEFINED__
#define __IFileSysNeptune_INTERFACE_DEFINED__

/* interface IFileSysNeptune */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileSysNeptune;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A306A531-DD64-4215-A487-BFA9C05D7954")
    IFileSysNeptune : public IFileSys
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MSI2XML( 
            /* [in] */ BSTR bstrMSIFile,
            /* [in] */ BSTR bstrXMLFile,
            /* [in] */ IProgressNeptune __RPC_FAR *pEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE XML2MSI( 
            /* [in] */ BSTR bstrXMLFile,
            /* [in] */ BSTR bstrMSIFile,
            /* [in] */ IProgressNeptune __RPC_FAR *pEvents) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileSysNeptuneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFileSysNeptune __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFileSysNeptune __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileCopy )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrSrcFile,
            /* [in] */ BSTR bstrTargetFile,
            /* [in] */ VARIANT_BOOL bOverWrite,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileExists )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrFile,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bExists);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDemo )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogError )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrMessage,
            /* [in] */ BSTR bstrUrl,
            /* [in] */ BSTR bstrLine);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsFileUnicode )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbIsUnicode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogMessage )( 
            IFileSysNeptune __RPC_FAR * This,
            BSTR bstrMessage,
            BSTR bstrFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileType )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [retval][out] */ EnumFileType __RPC_FAR *enumFileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsCPSupported )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bSupported);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsCPInstalled )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR sCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bInstalled);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVxdVersionInfoSize )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVxdVersionInfo )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ LONG Len,
            /* [out] */ LONG __RPC_FAR *dwFileVersionMS,
            /* [out] */ LONG __RPC_FAR *dwFileVersionLS,
            /* [out] */ BSTR __RPC_FAR *bstrVersion,
            /* [out] */ VARIANT __RPC_FAR *pLanguage,
            /* [out] */ VARIANT __RPC_FAR *pCodePage,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbSuccess);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShortLongFilename )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrFilename,
            /* [in] */ BSTR bstrLangID,
            /* [out] */ BSTR __RPC_FAR *bstrShortLongName,
            /* [retval][out] */ LONG __RPC_FAR *pResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MSI2XML )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrMSIFile,
            /* [in] */ BSTR bstrXMLFile,
            /* [in] */ IProgressNeptune __RPC_FAR *pEvents);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *XML2MSI )( 
            IFileSysNeptune __RPC_FAR * This,
            /* [in] */ BSTR bstrXMLFile,
            /* [in] */ BSTR bstrMSIFile,
            /* [in] */ IProgressNeptune __RPC_FAR *pEvents);
        
        END_INTERFACE
    } IFileSysNeptuneVtbl;

    interface IFileSysNeptune
    {
        CONST_VTBL struct IFileSysNeptuneVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileSysNeptune_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFileSysNeptune_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFileSysNeptune_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFileSysNeptune_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFileSysNeptune_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFileSysNeptune_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFileSysNeptune_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFileSysNeptune_FileCopy(This,bstrSrcFile,bstrTargetFile,bOverWrite,pResult)	\
    (This)->lpVtbl -> FileCopy(This,bstrSrcFile,bstrTargetFile,bOverWrite,pResult)

#define IFileSysNeptune_FileExists(This,bstrFile,bExists)	\
    (This)->lpVtbl -> FileExists(This,bstrFile,bExists)

#define IFileSysNeptune_ShowDemo(This,bstrPath,bstrFileName,vbSuccess)	\
    (This)->lpVtbl -> ShowDemo(This,bstrPath,bstrFileName,vbSuccess)

#define IFileSysNeptune_LogError(This,bstrMessage,bstrUrl,bstrLine)	\
    (This)->lpVtbl -> LogError(This,bstrMessage,bstrUrl,bstrLine)

#define IFileSysNeptune_IsFileUnicode(This,bstrFileName,vbIsUnicode)	\
    (This)->lpVtbl -> IsFileUnicode(This,bstrFileName,vbIsUnicode)

#define IFileSysNeptune_LogMessage(This,bstrMessage,bstrFileName)	\
    (This)->lpVtbl -> LogMessage(This,bstrMessage,bstrFileName)

#define IFileSysNeptune_FileType(This,sFileName,enumFileType)	\
    (This)->lpVtbl -> FileType(This,sFileName,enumFileType)

#define IFileSysNeptune_IsCPSupported(This,sCodePage,bSupported)	\
    (This)->lpVtbl -> IsCPSupported(This,sCodePage,bSupported)

#define IFileSysNeptune_IsCPInstalled(This,sCodePage,bInstalled)	\
    (This)->lpVtbl -> IsCPInstalled(This,sCodePage,bInstalled)

#define IFileSysNeptune_GetVxdVersionInfoSize(This,bstrFileName,pResult)	\
    (This)->lpVtbl -> GetVxdVersionInfoSize(This,bstrFileName,pResult)

#define IFileSysNeptune_GetVxdVersionInfo(This,bstrFileName,Len,dwFileVersionMS,dwFileVersionLS,bstrVersion,pLanguage,pCodePage,vbSuccess)	\
    (This)->lpVtbl -> GetVxdVersionInfo(This,bstrFileName,Len,dwFileVersionMS,dwFileVersionLS,bstrVersion,pLanguage,pCodePage,vbSuccess)

#define IFileSysNeptune_GetShortLongFilename(This,bstrFilename,bstrLangID,bstrShortLongName,pResult)	\
    (This)->lpVtbl -> GetShortLongFilename(This,bstrFilename,bstrLangID,bstrShortLongName,pResult)


#define IFileSysNeptune_MSI2XML(This,bstrMSIFile,bstrXMLFile,pEvents)	\
    (This)->lpVtbl -> MSI2XML(This,bstrMSIFile,bstrXMLFile,pEvents)

#define IFileSysNeptune_XML2MSI(This,bstrXMLFile,bstrMSIFile,pEvents)	\
    (This)->lpVtbl -> XML2MSI(This,bstrXMLFile,bstrMSIFile,pEvents)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFileSysNeptune_MSI2XML_Proxy( 
    IFileSysNeptune __RPC_FAR * This,
    /* [in] */ BSTR bstrMSIFile,
    /* [in] */ BSTR bstrXMLFile,
    /* [in] */ IProgressNeptune __RPC_FAR *pEvents);


void __RPC_STUB IFileSysNeptune_MSI2XML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFileSysNeptune_XML2MSI_Proxy( 
    IFileSysNeptune __RPC_FAR * This,
    /* [in] */ BSTR bstrXMLFile,
    /* [in] */ BSTR bstrMSIFile,
    /* [in] */ IProgressNeptune __RPC_FAR *pEvents);


void __RPC_STUB IFileSysNeptune_XML2MSI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFileSysNeptune_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SearchReplace;

#ifdef __cplusplus

class DECLSPEC_UUID("0DCA02CF-44FD-4398-AC65-B61FF12FB97A")
SearchReplace;
#endif

EXTERN_C const CLSID CLSID_Registry;

#ifdef __cplusplus

class DECLSPEC_UUID("FB44C66C-89FA-4DD5-A659-67F38E85BD92")
Registry;
#endif

EXTERN_C const CLSID CLSID_Guid;

#ifdef __cplusplus

class DECLSPEC_UUID("F1B6F62A-9AD2-476B-A183-7EE975A7C2C6")
Guid;
#endif

EXTERN_C const CLSID CLSID_File;

#ifdef __cplusplus

class DECLSPEC_UUID("A5CF09AF-F2FC-4E5D-9F7D-419D28130E62")
File;
#endif

EXTERN_C const CLSID CLSID_ISResXfer;

#ifdef __cplusplus

class DECLSPEC_UUID("85B121D5-A275-4050-88B7-69941BB2F1D8")
ISResXfer;
#endif

#ifndef __ServerInfoEvents_DISPINTERFACE_DEFINED__
#define __ServerInfoEvents_DISPINTERFACE_DEFINED__

/* dispinterface ServerInfoEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_ServerInfoEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ADFEC76F-4E2F-449C-88BB-F374669D7266")
    ServerInfoEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ServerInfoEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ServerInfoEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ServerInfoEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ServerInfoEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ServerInfoEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ServerInfoEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ServerInfoEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ServerInfoEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } ServerInfoEventsVtbl;

    interface ServerInfoEvents
    {
        CONST_VTBL struct ServerInfoEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ServerInfoEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ServerInfoEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ServerInfoEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ServerInfoEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ServerInfoEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ServerInfoEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ServerInfoEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ServerInfoEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ServerInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("85E34F82-D04F-44CF-9FB3-15891F73447A")
ServerInfo;
#endif

EXTERN_C const CLSID CLSID_PropertyHeader;

#ifdef __cplusplus

class DECLSPEC_UUID("F9EF9197-8B66-4974-989B-EEE5960E37B7")
PropertyHeader;
#endif

EXTERN_C const CLSID CLSID_Encryptor;

#ifdef __cplusplus

class DECLSPEC_UUID("E01F16DE-D788-4757-B9A8-CC44FE75F9D7")
Encryptor;
#endif

EXTERN_C const CLSID CLSID_SignCode;

#ifdef __cplusplus

class DECLSPEC_UUID("EE0B32E7-6F30-4059-A395-73D4272826FF")
SignCode;
#endif

EXTERN_C const CLSID CLSID_StampVersion;

#ifdef __cplusplus

class DECLSPEC_UUID("DBA5EA98-7DF6-430B-9F36-0A74D8C535AE")
StampVersion;
#endif
#endif /* __ISUtilityLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
