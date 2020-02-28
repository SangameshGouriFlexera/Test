/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Dec 08 15:11:34 2011
 */
/* Compiler settings for ..\..\src\Backend\Build\ISWIBuild\ISWIBuild.idl:
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

#ifndef __ISWIBuild_h__
#define __ISWIBuild_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IBuildEvent_FWD_DEFINED__
#define __IBuildEvent_FWD_DEFINED__
typedef interface IBuildEvent IBuildEvent;
#endif 	/* __IBuildEvent_FWD_DEFINED__ */


#ifndef __IBuildEventVsip_FWD_DEFINED__
#define __IBuildEventVsip_FWD_DEFINED__
typedef interface IBuildEventVsip IBuildEventVsip;
#endif 	/* __IBuildEventVsip_FWD_DEFINED__ */


#ifndef __IBuildEvent2_FWD_DEFINED__
#define __IBuildEvent2_FWD_DEFINED__
typedef interface IBuildEvent2 IBuildEvent2;
#endif 	/* __IBuildEvent2_FWD_DEFINED__ */


#ifndef __IBuildProjectOutputGroup_FWD_DEFINED__
#define __IBuildProjectOutputGroup_FWD_DEFINED__
typedef interface IBuildProjectOutputGroup IBuildProjectOutputGroup;
#endif 	/* __IBuildProjectOutputGroup_FWD_DEFINED__ */


#ifndef __IBuildDataOverrides_FWD_DEFINED__
#define __IBuildDataOverrides_FWD_DEFINED__
typedef interface IBuildDataOverrides IBuildDataOverrides;
#endif 	/* __IBuildDataOverrides_FWD_DEFINED__ */


#ifndef __IBuild_FWD_DEFINED__
#define __IBuild_FWD_DEFINED__
typedef interface IBuild IBuild;
#endif 	/* __IBuild_FWD_DEFINED__ */


#ifndef __IBuildNeptunePDC_FWD_DEFINED__
#define __IBuildNeptunePDC_FWD_DEFINED__
typedef interface IBuildNeptunePDC IBuildNeptunePDC;
#endif 	/* __IBuildNeptunePDC_FWD_DEFINED__ */


#ifndef __IBuildIndoreSP1_FWD_DEFINED__
#define __IBuildIndoreSP1_FWD_DEFINED__
typedef interface IBuildIndoreSP1 IBuildIndoreSP1;
#endif 	/* __IBuildIndoreSP1_FWD_DEFINED__ */


#ifndef __IBuildIronwood_FWD_DEFINED__
#define __IBuildIronwood_FWD_DEFINED__
typedef interface IBuildIronwood IBuildIronwood;
#endif 	/* __IBuildIronwood_FWD_DEFINED__ */


#ifndef __IBuildMajesty_FWD_DEFINED__
#define __IBuildMajesty_FWD_DEFINED__
typedef interface IBuildMajesty IBuildMajesty;
#endif 	/* __IBuildMajesty_FWD_DEFINED__ */


#ifndef __IBuildNeo_FWD_DEFINED__
#define __IBuildNeo_FWD_DEFINED__
typedef interface IBuildNeo IBuildNeo;
#endif 	/* __IBuildNeo_FWD_DEFINED__ */


#ifndef __Build_FWD_DEFINED__
#define __Build_FWD_DEFINED__

#ifdef __cplusplus
typedef class Build Build;
#else
typedef struct Build Build;
#endif /* __cplusplus */

#endif 	/* __Build_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __ISWIBUILDLib_LIBRARY_DEFINED__
#define __ISWIBUILDLib_LIBRARY_DEFINED__

/* library ISWIBUILDLib */
/* [helpstring][uuid][version] */ 

typedef /* [version][helpstring][uuid] */ 
enum BuildType
    {	Full	= 1,
	Quick	= 2,
	Refresh	= 4
    }	BuildType;

typedef /* [version][helpstring][uuid] */ 
enum BuildClient
    {	bcInstallShield	= 1,
	bcRepackager	= 2,
	bcCollaboration	= 3
    }	BuildClient;


EXTERN_C const IID LIBID_ISWIBUILDLib;

#ifndef __IBuildEvent_INTERFACE_DEFINED__
#define __IBuildEvent_INTERFACE_DEFINED__

/* interface IBuildEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED99E158-06A6-4f21-858B-BAEBEDB5C84F")
    IBuildEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StatusMessage( 
            /* [in] */ BSTR sMessage,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProgressMax( 
            /* [in] */ long lMax,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProgressIncrement( 
            /* [in] */ long lIncrement,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE TestCancel( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCancel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDotNetLibrary( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StatusMessage )( 
            IBuildEvent __RPC_FAR * This,
            /* [in] */ BSTR sMessage,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressMax )( 
            IBuildEvent __RPC_FAR * This,
            /* [in] */ long lMax,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressIncrement )( 
            IBuildEvent __RPC_FAR * This,
            /* [in] */ long lIncrement,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TestCancel )( 
            IBuildEvent __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDotNetLibrary )( 
            IBuildEvent __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppVal);
        
        END_INTERFACE
    } IBuildEventVtbl;

    interface IBuildEvent
    {
        CONST_VTBL struct IBuildEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildEvent_StatusMessage(This,sMessage,pbCancel)	\
    (This)->lpVtbl -> StatusMessage(This,sMessage,pbCancel)

#define IBuildEvent_ProgressMax(This,lMax,pbCancel)	\
    (This)->lpVtbl -> ProgressMax(This,lMax,pbCancel)

#define IBuildEvent_ProgressIncrement(This,lIncrement,pbCancel)	\
    (This)->lpVtbl -> ProgressIncrement(This,lIncrement,pbCancel)

#define IBuildEvent_TestCancel(This,pbCancel)	\
    (This)->lpVtbl -> TestCancel(This,pbCancel)

#define IBuildEvent_GetDotNetLibrary(This,ppVal)	\
    (This)->lpVtbl -> GetDotNetLibrary(This,ppVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent_StatusMessage_Proxy( 
    IBuildEvent __RPC_FAR * This,
    /* [in] */ BSTR sMessage,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);


void __RPC_STUB IBuildEvent_StatusMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent_ProgressMax_Proxy( 
    IBuildEvent __RPC_FAR * This,
    /* [in] */ long lMax,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);


void __RPC_STUB IBuildEvent_ProgressMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent_ProgressIncrement_Proxy( 
    IBuildEvent __RPC_FAR * This,
    /* [in] */ long lIncrement,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);


void __RPC_STUB IBuildEvent_ProgressIncrement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent_TestCancel_Proxy( 
    IBuildEvent __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCancel);


void __RPC_STUB IBuildEvent_TestCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent_GetDotNetLibrary_Proxy( 
    IBuildEvent __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppVal);


void __RPC_STUB IBuildEvent_GetDotNetLibrary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildEvent_INTERFACE_DEFINED__ */


#ifndef __IBuildEventVsip_INTERFACE_DEFINED__
#define __IBuildEventVsip_INTERFACE_DEFINED__

/* interface IBuildEventVsip */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildEventVsip;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7D23AF4C-5F38-41AE-96CA-D7A44D842C23")
    IBuildEventVsip : public IBuildEvent
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVsipProvider( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppVsServiceProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildEventVsipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildEventVsip __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildEventVsip __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StatusMessage )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [in] */ BSTR sMessage,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressMax )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [in] */ long lMax,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressIncrement )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [in] */ long lIncrement,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TestCancel )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDotNetLibrary )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVsipProvider )( 
            IBuildEventVsip __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppVsServiceProvider);
        
        END_INTERFACE
    } IBuildEventVsipVtbl;

    interface IBuildEventVsip
    {
        CONST_VTBL struct IBuildEventVsipVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildEventVsip_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildEventVsip_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildEventVsip_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildEventVsip_StatusMessage(This,sMessage,pbCancel)	\
    (This)->lpVtbl -> StatusMessage(This,sMessage,pbCancel)

#define IBuildEventVsip_ProgressMax(This,lMax,pbCancel)	\
    (This)->lpVtbl -> ProgressMax(This,lMax,pbCancel)

#define IBuildEventVsip_ProgressIncrement(This,lIncrement,pbCancel)	\
    (This)->lpVtbl -> ProgressIncrement(This,lIncrement,pbCancel)

#define IBuildEventVsip_TestCancel(This,pbCancel)	\
    (This)->lpVtbl -> TestCancel(This,pbCancel)

#define IBuildEventVsip_GetDotNetLibrary(This,ppVal)	\
    (This)->lpVtbl -> GetDotNetLibrary(This,ppVal)


#define IBuildEventVsip_GetVsipProvider(This,ppVsServiceProvider)	\
    (This)->lpVtbl -> GetVsipProvider(This,ppVsServiceProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBuildEventVsip_GetVsipProvider_Proxy( 
    IBuildEventVsip __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppVsServiceProvider);


void __RPC_STUB IBuildEventVsip_GetVsipProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildEventVsip_INTERFACE_DEFINED__ */


#ifndef __IBuildEvent2_INTERFACE_DEFINED__
#define __IBuildEvent2_INTERFACE_DEFINED__

/* interface IBuildEvent2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB16F037-B8DC-4ceb-AEE5-1F2752B3ADF2")
    IBuildEvent2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WarningMessage( 
            /* [in] */ BSTR sMessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ErrorMessage( 
            /* [in] */ BSTR sMessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsCancelledByUserAnError( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbShowError) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StatusMessageEx( 
            /* [in] */ BSTR sMessage,
            /* [in] */ VARIANT vTag,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildEvent2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildEvent2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildEvent2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WarningMessage )( 
            IBuildEvent2 __RPC_FAR * This,
            /* [in] */ BSTR sMessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ErrorMessage )( 
            IBuildEvent2 __RPC_FAR * This,
            /* [in] */ BSTR sMessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsCancelledByUserAnError )( 
            IBuildEvent2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbShowError);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StatusMessageEx )( 
            IBuildEvent2 __RPC_FAR * This,
            /* [in] */ BSTR sMessage,
            /* [in] */ VARIANT vTag,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);
        
        END_INTERFACE
    } IBuildEvent2Vtbl;

    interface IBuildEvent2
    {
        CONST_VTBL struct IBuildEvent2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildEvent2_WarningMessage(This,sMessage)	\
    (This)->lpVtbl -> WarningMessage(This,sMessage)

#define IBuildEvent2_ErrorMessage(This,sMessage)	\
    (This)->lpVtbl -> ErrorMessage(This,sMessage)

#define IBuildEvent2_IsCancelledByUserAnError(This,vbShowError)	\
    (This)->lpVtbl -> IsCancelledByUserAnError(This,vbShowError)

#define IBuildEvent2_StatusMessageEx(This,sMessage,vTag,pbCancel)	\
    (This)->lpVtbl -> StatusMessageEx(This,sMessage,vTag,pbCancel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent2_WarningMessage_Proxy( 
    IBuildEvent2 __RPC_FAR * This,
    /* [in] */ BSTR sMessage);


void __RPC_STUB IBuildEvent2_WarningMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent2_ErrorMessage_Proxy( 
    IBuildEvent2 __RPC_FAR * This,
    /* [in] */ BSTR sMessage);


void __RPC_STUB IBuildEvent2_ErrorMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent2_IsCancelledByUserAnError_Proxy( 
    IBuildEvent2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *vbShowError);


void __RPC_STUB IBuildEvent2_IsCancelledByUserAnError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuildEvent2_StatusMessageEx_Proxy( 
    IBuildEvent2 __RPC_FAR * This,
    /* [in] */ BSTR sMessage,
    /* [in] */ VARIANT vTag,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *pbCancel);


void __RPC_STUB IBuildEvent2_StatusMessageEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildEvent2_INTERFACE_DEFINED__ */


#ifndef __IBuildProjectOutputGroup_INTERFACE_DEFINED__
#define __IBuildProjectOutputGroup_INTERFACE_DEFINED__

/* interface IBuildProjectOutputGroup */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildProjectOutputGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04917939-1DFF-487C-92E1-AB44F4D86802")
    IBuildProjectOutputGroup : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [retval][out] */ long __RPC_FAR *plCount) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FilePath( 
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [in] */ long lIndex,
            /* [retval][out] */ BSTR __RPC_FAR *pvFile) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FileTarget( 
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [in] */ long lIndex,
            /* [retval][out] */ BSTR __RPC_FAR *pvFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildProjectOutputGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildProjectOutputGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildProjectOutputGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildProjectOutputGroup __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IBuildProjectOutputGroup __RPC_FAR * This,
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FilePath )( 
            IBuildProjectOutputGroup __RPC_FAR * This,
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [in] */ long lIndex,
            /* [retval][out] */ BSTR __RPC_FAR *pvFile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileTarget )( 
            IBuildProjectOutputGroup __RPC_FAR * This,
            /* [in] */ BSTR sProject,
            /* [in] */ BSTR sGroup,
            /* [in] */ long lIndex,
            /* [retval][out] */ BSTR __RPC_FAR *pvFile);
        
        END_INTERFACE
    } IBuildProjectOutputGroupVtbl;

    interface IBuildProjectOutputGroup
    {
        CONST_VTBL struct IBuildProjectOutputGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildProjectOutputGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildProjectOutputGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildProjectOutputGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildProjectOutputGroup_get_Count(This,sProject,sGroup,plCount)	\
    (This)->lpVtbl -> get_Count(This,sProject,sGroup,plCount)

#define IBuildProjectOutputGroup_get_FilePath(This,sProject,sGroup,lIndex,pvFile)	\
    (This)->lpVtbl -> get_FilePath(This,sProject,sGroup,lIndex,pvFile)

#define IBuildProjectOutputGroup_get_FileTarget(This,sProject,sGroup,lIndex,pvFile)	\
    (This)->lpVtbl -> get_FileTarget(This,sProject,sGroup,lIndex,pvFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildProjectOutputGroup_get_Count_Proxy( 
    IBuildProjectOutputGroup __RPC_FAR * This,
    /* [in] */ BSTR sProject,
    /* [in] */ BSTR sGroup,
    /* [retval][out] */ long __RPC_FAR *plCount);


void __RPC_STUB IBuildProjectOutputGroup_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildProjectOutputGroup_get_FilePath_Proxy( 
    IBuildProjectOutputGroup __RPC_FAR * This,
    /* [in] */ BSTR sProject,
    /* [in] */ BSTR sGroup,
    /* [in] */ long lIndex,
    /* [retval][out] */ BSTR __RPC_FAR *pvFile);


void __RPC_STUB IBuildProjectOutputGroup_get_FilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildProjectOutputGroup_get_FileTarget_Proxy( 
    IBuildProjectOutputGroup __RPC_FAR * This,
    /* [in] */ BSTR sProject,
    /* [in] */ BSTR sGroup,
    /* [in] */ long lIndex,
    /* [retval][out] */ BSTR __RPC_FAR *pvFile);


void __RPC_STUB IBuildProjectOutputGroup_get_FileTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildProjectOutputGroup_INTERFACE_DEFINED__ */


#ifndef __IBuildDataOverrides_INTERFACE_DEFINED__
#define __IBuildDataOverrides_INTERFACE_DEFINED__

/* interface IBuildDataOverrides */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildDataOverrides;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1B2AB78F-19DC-4769-8815-C4780668086C")
    IBuildDataOverrides : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreprocessorDefines( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrDefines) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PathVariableOverride( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR __RPC_FAR *bstrOverride) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildDataOverridesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildDataOverrides __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildDataOverrides __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildDataOverrides __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PreprocessorDefines )( 
            IBuildDataOverrides __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrDefines);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PathVariableOverride )( 
            IBuildDataOverrides __RPC_FAR * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR __RPC_FAR *bstrOverride);
        
        END_INTERFACE
    } IBuildDataOverridesVtbl;

    interface IBuildDataOverrides
    {
        CONST_VTBL struct IBuildDataOverridesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildDataOverrides_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildDataOverrides_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildDataOverrides_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildDataOverrides_get_PreprocessorDefines(This,bstrDefines)	\
    (This)->lpVtbl -> get_PreprocessorDefines(This,bstrDefines)

#define IBuildDataOverrides_get_PathVariableOverride(This,bstrPath,bstrOverride)	\
    (This)->lpVtbl -> get_PathVariableOverride(This,bstrPath,bstrOverride)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildDataOverrides_get_PreprocessorDefines_Proxy( 
    IBuildDataOverrides __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrDefines);


void __RPC_STUB IBuildDataOverrides_get_PreprocessorDefines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildDataOverrides_get_PathVariableOverride_Proxy( 
    IBuildDataOverrides __RPC_FAR * This,
    /* [in] */ BSTR bstrPath,
    /* [retval][out] */ BSTR __RPC_FAR *bstrOverride);


void __RPC_STUB IBuildDataOverrides_get_PathVariableOverride_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildDataOverrides_INTERFACE_DEFINED__ */


#ifndef __IBuild_INTERFACE_DEFINED__
#define __IBuild_INTERFACE_DEFINED__

/* interface IBuild */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuild;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CC236C64-7829-496c-9154-6A72408BEDD3")
    IBuild : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BuildType( 
            /* [retval][out] */ BuildType __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BuildType( 
            /* [in] */ BuildType newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReleaseFolder( 
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReleaseFolder( 
            /* [in] */ BSTR sReleaseFolder) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReleaseFlags( 
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReleaseFlags( 
            /* [in] */ BSTR sReleaseFlags) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Compressed( 
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Compressed( 
            /* [in] */ BSTR sCompressed) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SetupExe( 
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SetupExe( 
            /* [in] */ BSTR sSetupExe) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StopAtFirstError( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_StopAtFirstError( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_WarningAsError( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_WarningAsError( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Verbose( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Verbose( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitEx( 
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BuildMedia( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CompileScript( 
            /* [in] */ BSTR sFileName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_WarningCount( 
            /* [retval][out] */ long __RPC_FAR *plCount) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorCount( 
            /* [retval][out] */ long __RPC_FAR *plCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Unadvise( 
            long dwCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OutputBuildErrorCodes( 
            /* [in] */ BSTR sFileName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_NoCompile( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ProductConfiguration( 
            /* [in] */ BSTR sProductConfiguration) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Release( 
            /* [in] */ BSTR sRelease) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_UpgradeOnly( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Silent( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoUpgradeAndBuild( 
            /* [in] */ BSTR sFileName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoUpgradeAndBuildEx( 
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DotNetBuildConfiguration( 
            /* [in] */ BSTR sDotNetBuildConfiguration) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsUpToDate( 
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Validate( void) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_CubFile( 
            /* [in] */ BSTR bstrCubFile) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitQuickPatch( 
            /* [in] */ IUnknown __RPC_FAR *pProject) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BuildQuickPatch( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitPatchConfiguration( 
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BuildPatchConfiguration( 
            VARIANT_BOOL bExportOnly) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ImportDialog( 
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MergeMM( 
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExtractFilesFromMergeModule( 
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuild __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuild __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuild __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuild __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuild __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuild __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuild __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuild __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuild __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuild __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuild __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuild __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuild __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        END_INTERFACE
    } IBuildVtbl;

    interface IBuild
    {
        CONST_VTBL struct IBuildVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuild_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuild_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuild_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuild_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuild_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuild_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuild_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuild_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuild_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuild_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuild_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuild_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuild_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuild_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuild_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuild_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuild_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuild_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuild_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuild_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuild_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuild_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuild_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuild_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuild_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuild_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuild_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuild_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuild_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuild_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuild_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuild_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuild_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuild_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuild_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuild_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuild_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuild_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuild_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuild_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuild_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuild_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuild_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuild_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuild_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuild_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_BuildType_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ BuildType __RPC_FAR *pVal);


void __RPC_STUB IBuild_get_BuildType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_BuildType_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BuildType newVal);


void __RPC_STUB IBuild_put_BuildType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_ReleaseFolder_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);


void __RPC_STUB IBuild_get_ReleaseFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_ReleaseFolder_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sReleaseFolder);


void __RPC_STUB IBuild_put_ReleaseFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_ReleaseFlags_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);


void __RPC_STUB IBuild_get_ReleaseFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_ReleaseFlags_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sReleaseFlags);


void __RPC_STUB IBuild_put_ReleaseFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_Compressed_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *psCompressed);


void __RPC_STUB IBuild_get_Compressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_Compressed_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sCompressed);


void __RPC_STUB IBuild_put_Compressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_SetupExe_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);


void __RPC_STUB IBuild_get_SetupExe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_SetupExe_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sSetupExe);


void __RPC_STUB IBuild_put_SetupExe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_StopAtFirstError_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBuild_get_StopAtFirstError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_StopAtFirstError_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBuild_put_StopAtFirstError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_WarningAsError_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBuild_get_WarningAsError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_WarningAsError_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBuild_put_WarningAsError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_Verbose_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBuild_get_Verbose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_Verbose_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBuild_put_Verbose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_Advise_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
    /* [retval][out] */ long __RPC_FAR *pdwCookie);


void __RPC_STUB IBuild_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_Init_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pProject,
    /* [in] */ BSTR sProductConfiguration,
    /* [in] */ BSTR sRelease);


void __RPC_STUB IBuild_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_InitEx_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pProject,
    /* [in] */ BSTR sProductConfiguration,
    /* [in] */ BSTR sRelease);


void __RPC_STUB IBuild_InitEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_BuildMedia_Proxy( 
    IBuild __RPC_FAR * This);


void __RPC_STUB IBuild_BuildMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_CompileScript_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sFileName);


void __RPC_STUB IBuild_CompileScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_WarningCount_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plCount);


void __RPC_STUB IBuild_get_WarningCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuild_get_ErrorCount_Proxy( 
    IBuild __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plCount);


void __RPC_STUB IBuild_get_ErrorCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_Unadvise_Proxy( 
    IBuild __RPC_FAR * This,
    long dwCookie);


void __RPC_STUB IBuild_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_OutputBuildErrorCodes_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sFileName);


void __RPC_STUB IBuild_OutputBuildErrorCodes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_NoCompile_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IBuild_put_NoCompile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_ProductConfiguration_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sProductConfiguration);


void __RPC_STUB IBuild_put_ProductConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_Release_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sRelease);


void __RPC_STUB IBuild_put_Release_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_UpgradeOnly_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IBuild_put_UpgradeOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_Silent_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IBuild_put_Silent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_DoUpgradeAndBuild_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sFileName);


void __RPC_STUB IBuild_DoUpgradeAndBuild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_DoUpgradeAndBuildEx_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sFileName,
    /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);


void __RPC_STUB IBuild_DoUpgradeAndBuildEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_DotNetBuildConfiguration_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR sDotNetBuildConfiguration);


void __RPC_STUB IBuild_put_DotNetBuildConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_IsUpToDate_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ long dwLowDateTime,
    /* [in] */ long dwHighDateTime,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);


void __RPC_STUB IBuild_IsUpToDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_Validate_Proxy( 
    IBuild __RPC_FAR * This);


void __RPC_STUB IBuild_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuild_put_CubFile_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ BSTR bstrCubFile);


void __RPC_STUB IBuild_put_CubFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_InitQuickPatch_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pProject);


void __RPC_STUB IBuild_InitQuickPatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_BuildQuickPatch_Proxy( 
    IBuild __RPC_FAR * This);


void __RPC_STUB IBuild_BuildQuickPatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_InitPatchConfiguration_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pProject,
    BSTR bstrConfiguration);


void __RPC_STUB IBuild_InitPatchConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_BuildPatchConfiguration_Proxy( 
    IBuild __RPC_FAR * This,
    VARIANT_BOOL bExportOnly);


void __RPC_STUB IBuild_BuildPatchConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_ImportDialog_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pIsdProject,
    /* [in] */ IUnknown __RPC_FAR *pTargetMsi);


void __RPC_STUB IBuild_ImportDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_MergeMM_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
    /* [in] */ IUnknown __RPC_FAR *pFeature,
    /* [in] */ IUnknown __RPC_FAR *pMergeModule);


void __RPC_STUB IBuild_MergeMM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBuild_ExtractFilesFromMergeModule_Proxy( 
    IBuild __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pMergeModule,
    /* [in] */ BSTR bstrDirToExtract);


void __RPC_STUB IBuild_ExtractFilesFromMergeModule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuild_INTERFACE_DEFINED__ */


#ifndef __IBuildNeptunePDC_INTERFACE_DEFINED__
#define __IBuildNeptunePDC_INTERFACE_DEFINED__

/* interface IBuildNeptunePDC */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildNeptunePDC;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CC236C65-7829-496c-9154-6A72408BEDD3")
    IBuildNeptunePDC : public IBuild
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BuildClickOnce( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitClickOnce( 
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildNeptunePDCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuildNeptunePDC __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuildNeptunePDC __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildClickOnce )( 
            IBuildNeptunePDC __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitClickOnce )( 
            IBuildNeptunePDC __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        END_INTERFACE
    } IBuildNeptunePDCVtbl;

    interface IBuildNeptunePDC
    {
        CONST_VTBL struct IBuildNeptunePDCVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildNeptunePDC_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildNeptunePDC_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildNeptunePDC_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildNeptunePDC_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuildNeptunePDC_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuildNeptunePDC_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuildNeptunePDC_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuildNeptunePDC_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuildNeptunePDC_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuildNeptunePDC_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuildNeptunePDC_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuildNeptunePDC_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuildNeptunePDC_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuildNeptunePDC_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuildNeptunePDC_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuildNeptunePDC_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuildNeptunePDC_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuildNeptunePDC_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuildNeptunePDC_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuildNeptunePDC_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuildNeptunePDC_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuildNeptunePDC_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuildNeptunePDC_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuildNeptunePDC_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuildNeptunePDC_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuildNeptunePDC_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuildNeptunePDC_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuildNeptunePDC_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuildNeptunePDC_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuildNeptunePDC_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuildNeptunePDC_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuildNeptunePDC_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuildNeptunePDC_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuildNeptunePDC_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuildNeptunePDC_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuildNeptunePDC_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuildNeptunePDC_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuildNeptunePDC_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuildNeptunePDC_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuildNeptunePDC_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuildNeptunePDC_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuildNeptunePDC_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuildNeptunePDC_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuildNeptunePDC_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuildNeptunePDC_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuildNeptunePDC_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)


#define IBuildNeptunePDC_BuildClickOnce(This)	\
    (This)->lpVtbl -> BuildClickOnce(This)

#define IBuildNeptunePDC_InitClickOnce(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitClickOnce(This,pProject,bstrConfiguration)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBuildNeptunePDC_BuildClickOnce_Proxy( 
    IBuildNeptunePDC __RPC_FAR * This);


void __RPC_STUB IBuildNeptunePDC_BuildClickOnce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBuildNeptunePDC_InitClickOnce_Proxy( 
    IBuildNeptunePDC __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pProject,
    BSTR bstrConfiguration);


void __RPC_STUB IBuildNeptunePDC_InitClickOnce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildNeptunePDC_INTERFACE_DEFINED__ */


#ifndef __IBuildIndoreSP1_INTERFACE_DEFINED__
#define __IBuildIndoreSP1_INTERFACE_DEFINED__

/* interface IBuildIndoreSP1 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildIndoreSP1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0D03C53-FAC8-4304-82D6-8F6EAC6B1FB8")
    IBuildIndoreSP1 : public IBuildNeptunePDC
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BuildVirtualPackage( 
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildIndoreSP1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildClickOnce )( 
            IBuildIndoreSP1 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitClickOnce )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildVirtualPackage )( 
            IBuildIndoreSP1 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);
        
        END_INTERFACE
    } IBuildIndoreSP1Vtbl;

    interface IBuildIndoreSP1
    {
        CONST_VTBL struct IBuildIndoreSP1Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildIndoreSP1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildIndoreSP1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildIndoreSP1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildIndoreSP1_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuildIndoreSP1_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuildIndoreSP1_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuildIndoreSP1_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuildIndoreSP1_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuildIndoreSP1_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuildIndoreSP1_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuildIndoreSP1_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuildIndoreSP1_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuildIndoreSP1_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuildIndoreSP1_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuildIndoreSP1_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuildIndoreSP1_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuildIndoreSP1_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuildIndoreSP1_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuildIndoreSP1_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuildIndoreSP1_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuildIndoreSP1_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuildIndoreSP1_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuildIndoreSP1_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuildIndoreSP1_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuildIndoreSP1_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuildIndoreSP1_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuildIndoreSP1_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuildIndoreSP1_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuildIndoreSP1_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuildIndoreSP1_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuildIndoreSP1_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuildIndoreSP1_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuildIndoreSP1_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuildIndoreSP1_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuildIndoreSP1_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuildIndoreSP1_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuildIndoreSP1_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuildIndoreSP1_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuildIndoreSP1_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuildIndoreSP1_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuildIndoreSP1_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuildIndoreSP1_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuildIndoreSP1_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuildIndoreSP1_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuildIndoreSP1_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuildIndoreSP1_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)


#define IBuildIndoreSP1_BuildClickOnce(This)	\
    (This)->lpVtbl -> BuildClickOnce(This)

#define IBuildIndoreSP1_InitClickOnce(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitClickOnce(This,pProject,bstrConfiguration)


#define IBuildIndoreSP1_BuildVirtualPackage(This,pUnkSrcProject)	\
    (This)->lpVtbl -> BuildVirtualPackage(This,pUnkSrcProject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBuildIndoreSP1_BuildVirtualPackage_Proxy( 
    IBuildIndoreSP1 __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);


void __RPC_STUB IBuildIndoreSP1_BuildVirtualPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildIndoreSP1_INTERFACE_DEFINED__ */


#ifndef __IBuildIronwood_INTERFACE_DEFINED__
#define __IBuildIronwood_INTERFACE_DEFINED__

/* interface IBuildIronwood */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildIronwood;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB5A7E28-3213-49fa-B625-FE511520B994")
    IBuildIronwood : public IBuildIndoreSP1
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProductVersion( 
            /* [retval][out] */ BSTR __RPC_FAR *bstrVersion) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ProductVersion( 
            /* [in] */ BSTR bstrVersion) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MSIPropertyOverride( 
            /* [in] */ BSTR bstrTok,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MSIPropertyOverride( 
            /* [in] */ BSTR bstrTok,
            /* [in] */ BSTR bstrVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildIronwoodVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildIronwood __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildIronwood __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuildIronwood __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuildIronwood __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuildIronwood __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuildIronwood __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuildIronwood __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildClickOnce )( 
            IBuildIronwood __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitClickOnce )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildVirtualPackage )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProductVersion )( 
            IBuildIronwood __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVersion);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductVersion )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR bstrVersion);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MSIPropertyOverride )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MSIPropertyOverride )( 
            IBuildIronwood __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [in] */ BSTR bstrVal);
        
        END_INTERFACE
    } IBuildIronwoodVtbl;

    interface IBuildIronwood
    {
        CONST_VTBL struct IBuildIronwoodVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildIronwood_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildIronwood_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildIronwood_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildIronwood_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuildIronwood_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuildIronwood_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuildIronwood_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuildIronwood_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuildIronwood_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuildIronwood_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuildIronwood_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuildIronwood_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuildIronwood_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuildIronwood_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuildIronwood_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuildIronwood_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuildIronwood_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuildIronwood_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuildIronwood_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuildIronwood_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuildIronwood_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuildIronwood_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuildIronwood_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuildIronwood_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuildIronwood_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuildIronwood_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuildIronwood_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuildIronwood_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuildIronwood_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuildIronwood_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuildIronwood_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuildIronwood_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuildIronwood_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuildIronwood_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuildIronwood_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuildIronwood_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuildIronwood_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuildIronwood_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuildIronwood_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuildIronwood_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuildIronwood_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuildIronwood_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuildIronwood_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuildIronwood_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuildIronwood_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuildIronwood_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)


#define IBuildIronwood_BuildClickOnce(This)	\
    (This)->lpVtbl -> BuildClickOnce(This)

#define IBuildIronwood_InitClickOnce(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitClickOnce(This,pProject,bstrConfiguration)


#define IBuildIronwood_BuildVirtualPackage(This,pUnkSrcProject)	\
    (This)->lpVtbl -> BuildVirtualPackage(This,pUnkSrcProject)


#define IBuildIronwood_get_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> get_ProductVersion(This,bstrVersion)

#define IBuildIronwood_put_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> put_ProductVersion(This,bstrVersion)

#define IBuildIronwood_get_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> get_MSIPropertyOverride(This,bstrTok,bstrVal)

#define IBuildIronwood_put_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> put_MSIPropertyOverride(This,bstrTok,bstrVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildIronwood_get_ProductVersion_Proxy( 
    IBuildIronwood __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *bstrVersion);


void __RPC_STUB IBuildIronwood_get_ProductVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuildIronwood_put_ProductVersion_Proxy( 
    IBuildIronwood __RPC_FAR * This,
    /* [in] */ BSTR bstrVersion);


void __RPC_STUB IBuildIronwood_put_ProductVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBuildIronwood_get_MSIPropertyOverride_Proxy( 
    IBuildIronwood __RPC_FAR * This,
    /* [in] */ BSTR bstrTok,
    /* [retval][out] */ BSTR __RPC_FAR *bstrVal);


void __RPC_STUB IBuildIronwood_get_MSIPropertyOverride_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuildIronwood_put_MSIPropertyOverride_Proxy( 
    IBuildIronwood __RPC_FAR * This,
    /* [in] */ BSTR bstrTok,
    /* [in] */ BSTR bstrVal);


void __RPC_STUB IBuildIronwood_put_MSIPropertyOverride_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildIronwood_INTERFACE_DEFINED__ */


#ifndef __IBuildMajesty_INTERFACE_DEFINED__
#define __IBuildMajesty_INTERFACE_DEFINED__

/* interface IBuildMajesty */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildMajesty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B10CA01-97C8-457b-80DA-8CAE7A77316D")
    IBuildMajesty : public IBuildIronwood
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BuildClientType( 
            /* [in] */ BuildClient newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildMajestyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildMajesty __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildMajesty __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuildMajesty __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuildMajesty __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuildMajesty __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuildMajesty __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuildMajesty __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildClickOnce )( 
            IBuildMajesty __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitClickOnce )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildVirtualPackage )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProductVersion )( 
            IBuildMajesty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVersion);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductVersion )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR bstrVersion);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MSIPropertyOverride )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MSIPropertyOverride )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [in] */ BSTR bstrVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildClientType )( 
            IBuildMajesty __RPC_FAR * This,
            /* [in] */ BuildClient newVal);
        
        END_INTERFACE
    } IBuildMajestyVtbl;

    interface IBuildMajesty
    {
        CONST_VTBL struct IBuildMajestyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildMajesty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildMajesty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildMajesty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildMajesty_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuildMajesty_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuildMajesty_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuildMajesty_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuildMajesty_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuildMajesty_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuildMajesty_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuildMajesty_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuildMajesty_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuildMajesty_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuildMajesty_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuildMajesty_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuildMajesty_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuildMajesty_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuildMajesty_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuildMajesty_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuildMajesty_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuildMajesty_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuildMajesty_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuildMajesty_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuildMajesty_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuildMajesty_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuildMajesty_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuildMajesty_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuildMajesty_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuildMajesty_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuildMajesty_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuildMajesty_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuildMajesty_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuildMajesty_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuildMajesty_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuildMajesty_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuildMajesty_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuildMajesty_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuildMajesty_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuildMajesty_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuildMajesty_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuildMajesty_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuildMajesty_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuildMajesty_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuildMajesty_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuildMajesty_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuildMajesty_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)


#define IBuildMajesty_BuildClickOnce(This)	\
    (This)->lpVtbl -> BuildClickOnce(This)

#define IBuildMajesty_InitClickOnce(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitClickOnce(This,pProject,bstrConfiguration)


#define IBuildMajesty_BuildVirtualPackage(This,pUnkSrcProject)	\
    (This)->lpVtbl -> BuildVirtualPackage(This,pUnkSrcProject)


#define IBuildMajesty_get_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> get_ProductVersion(This,bstrVersion)

#define IBuildMajesty_put_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> put_ProductVersion(This,bstrVersion)

#define IBuildMajesty_get_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> get_MSIPropertyOverride(This,bstrTok,bstrVal)

#define IBuildMajesty_put_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> put_MSIPropertyOverride(This,bstrTok,bstrVal)


#define IBuildMajesty_put_BuildClientType(This,newVal)	\
    (This)->lpVtbl -> put_BuildClientType(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IBuildMajesty_put_BuildClientType_Proxy( 
    IBuildMajesty __RPC_FAR * This,
    /* [in] */ BuildClient newVal);


void __RPC_STUB IBuildMajesty_put_BuildClientType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildMajesty_INTERFACE_DEFINED__ */


#ifndef __IBuildNeo_INTERFACE_DEFINED__
#define __IBuildNeo_INTERFACE_DEFINED__

/* interface IBuildNeo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuildNeo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("617AB28B-87DF-40DD-BA85-4820541CC444")
    IBuildNeo : public IBuildMajesty
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BuildFragmentUnitTest( 
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BuildSuiteProject( 
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject,
            /* [in] */ BSTR bstrRelease) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBuildNeoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBuildNeo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBuildNeo __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuildType )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BuildType __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildType )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BuildType newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFolder )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFolder);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFolder )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFolder);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReleaseFlags )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psReleaseFlags);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReleaseFlags )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sReleaseFlags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Compressed )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psCompressed);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Compressed )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sCompressed);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SetupExe )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *psSetupExe);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SetupExe )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sSetupExe);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopAtFirstError )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopAtFirstError )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningAsError )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WarningAsError )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IBuildEvent __RPC_FAR *pBuildEvent,
            /* [retval][out] */ long __RPC_FAR *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitEx )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            /* [in] */ BSTR sProductConfiguration,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildMedia )( 
            IBuildNeo __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompileScript )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WarningCount )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorCount )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unadvise )( 
            IBuildNeo __RPC_FAR * This,
            long dwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputBuildErrorCodes )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NoCompile )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductConfiguration )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sProductConfiguration);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Release )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UpgradeOnly )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Silent )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuild )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoUpgradeAndBuildEx )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sFileName,
            /* [in] */ VARIANT_BOOL bAlwaysCreateRelease);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DotNetBuildConfiguration )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR sDotNetBuildConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsUpToDate )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ long dwLowDateTime,
            /* [in] */ long dwHighDateTime,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pvbUpToDate);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IBuildNeo __RPC_FAR * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CubFile )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR bstrCubFile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitQuickPatch )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildQuickPatch )( 
            IBuildNeo __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPatchConfiguration )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPatchConfiguration )( 
            IBuildNeo __RPC_FAR * This,
            VARIANT_BOOL bExportOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportDialog )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pIsdProject,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeMM )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pTargetMsi,
            /* [in] */ IUnknown __RPC_FAR *pFeature,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExtractFilesFromMergeModule )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pMergeModule,
            /* [in] */ BSTR bstrDirToExtract);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildClickOnce )( 
            IBuildNeo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitClickOnce )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pProject,
            BSTR bstrConfiguration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildVirtualPackage )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProductVersion )( 
            IBuildNeo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVersion);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProductVersion )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR bstrVersion);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MSIPropertyOverride )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [retval][out] */ BSTR __RPC_FAR *bstrVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MSIPropertyOverride )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BSTR bstrTok,
            /* [in] */ BSTR bstrVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BuildClientType )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ BuildClient newVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildFragmentUnitTest )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildSuiteProject )( 
            IBuildNeo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject,
            /* [in] */ BSTR bstrRelease);
        
        END_INTERFACE
    } IBuildNeoVtbl;

    interface IBuildNeo
    {
        CONST_VTBL struct IBuildNeoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuildNeo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBuildNeo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBuildNeo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBuildNeo_get_BuildType(This,pVal)	\
    (This)->lpVtbl -> get_BuildType(This,pVal)

#define IBuildNeo_put_BuildType(This,newVal)	\
    (This)->lpVtbl -> put_BuildType(This,newVal)

#define IBuildNeo_get_ReleaseFolder(This,psReleaseFolder)	\
    (This)->lpVtbl -> get_ReleaseFolder(This,psReleaseFolder)

#define IBuildNeo_put_ReleaseFolder(This,sReleaseFolder)	\
    (This)->lpVtbl -> put_ReleaseFolder(This,sReleaseFolder)

#define IBuildNeo_get_ReleaseFlags(This,psReleaseFlags)	\
    (This)->lpVtbl -> get_ReleaseFlags(This,psReleaseFlags)

#define IBuildNeo_put_ReleaseFlags(This,sReleaseFlags)	\
    (This)->lpVtbl -> put_ReleaseFlags(This,sReleaseFlags)

#define IBuildNeo_get_Compressed(This,psCompressed)	\
    (This)->lpVtbl -> get_Compressed(This,psCompressed)

#define IBuildNeo_put_Compressed(This,sCompressed)	\
    (This)->lpVtbl -> put_Compressed(This,sCompressed)

#define IBuildNeo_get_SetupExe(This,psSetupExe)	\
    (This)->lpVtbl -> get_SetupExe(This,psSetupExe)

#define IBuildNeo_put_SetupExe(This,sSetupExe)	\
    (This)->lpVtbl -> put_SetupExe(This,sSetupExe)

#define IBuildNeo_get_StopAtFirstError(This,pVal)	\
    (This)->lpVtbl -> get_StopAtFirstError(This,pVal)

#define IBuildNeo_put_StopAtFirstError(This,newVal)	\
    (This)->lpVtbl -> put_StopAtFirstError(This,newVal)

#define IBuildNeo_get_WarningAsError(This,pVal)	\
    (This)->lpVtbl -> get_WarningAsError(This,pVal)

#define IBuildNeo_put_WarningAsError(This,newVal)	\
    (This)->lpVtbl -> put_WarningAsError(This,newVal)

#define IBuildNeo_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IBuildNeo_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IBuildNeo_Advise(This,pBuildEvent,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pBuildEvent,pdwCookie)

#define IBuildNeo_Init(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> Init(This,pProject,sProductConfiguration,sRelease)

#define IBuildNeo_InitEx(This,pProject,sProductConfiguration,sRelease)	\
    (This)->lpVtbl -> InitEx(This,pProject,sProductConfiguration,sRelease)

#define IBuildNeo_BuildMedia(This)	\
    (This)->lpVtbl -> BuildMedia(This)

#define IBuildNeo_CompileScript(This,sFileName)	\
    (This)->lpVtbl -> CompileScript(This,sFileName)

#define IBuildNeo_get_WarningCount(This,plCount)	\
    (This)->lpVtbl -> get_WarningCount(This,plCount)

#define IBuildNeo_get_ErrorCount(This,plCount)	\
    (This)->lpVtbl -> get_ErrorCount(This,plCount)

#define IBuildNeo_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IBuildNeo_OutputBuildErrorCodes(This,sFileName)	\
    (This)->lpVtbl -> OutputBuildErrorCodes(This,sFileName)

#define IBuildNeo_put_NoCompile(This,pVal)	\
    (This)->lpVtbl -> put_NoCompile(This,pVal)

#define IBuildNeo_put_ProductConfiguration(This,sProductConfiguration)	\
    (This)->lpVtbl -> put_ProductConfiguration(This,sProductConfiguration)

#define IBuildNeo_put_Release(This,sRelease)	\
    (This)->lpVtbl -> put_Release(This,sRelease)

#define IBuildNeo_put_UpgradeOnly(This,pVal)	\
    (This)->lpVtbl -> put_UpgradeOnly(This,pVal)

#define IBuildNeo_put_Silent(This,pVal)	\
    (This)->lpVtbl -> put_Silent(This,pVal)

#define IBuildNeo_DoUpgradeAndBuild(This,sFileName)	\
    (This)->lpVtbl -> DoUpgradeAndBuild(This,sFileName)

#define IBuildNeo_DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)	\
    (This)->lpVtbl -> DoUpgradeAndBuildEx(This,sFileName,bAlwaysCreateRelease)

#define IBuildNeo_put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)	\
    (This)->lpVtbl -> put_DotNetBuildConfiguration(This,sDotNetBuildConfiguration)

#define IBuildNeo_IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)	\
    (This)->lpVtbl -> IsUpToDate(This,dwLowDateTime,dwHighDateTime,pvbUpToDate)

#define IBuildNeo_Validate(This)	\
    (This)->lpVtbl -> Validate(This)

#define IBuildNeo_put_CubFile(This,bstrCubFile)	\
    (This)->lpVtbl -> put_CubFile(This,bstrCubFile)

#define IBuildNeo_InitQuickPatch(This,pProject)	\
    (This)->lpVtbl -> InitQuickPatch(This,pProject)

#define IBuildNeo_BuildQuickPatch(This)	\
    (This)->lpVtbl -> BuildQuickPatch(This)

#define IBuildNeo_InitPatchConfiguration(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitPatchConfiguration(This,pProject,bstrConfiguration)

#define IBuildNeo_BuildPatchConfiguration(This,bExportOnly)	\
    (This)->lpVtbl -> BuildPatchConfiguration(This,bExportOnly)

#define IBuildNeo_ImportDialog(This,pIsdProject,pTargetMsi)	\
    (This)->lpVtbl -> ImportDialog(This,pIsdProject,pTargetMsi)

#define IBuildNeo_MergeMM(This,pTargetMsi,pFeature,pMergeModule)	\
    (This)->lpVtbl -> MergeMM(This,pTargetMsi,pFeature,pMergeModule)

#define IBuildNeo_ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)	\
    (This)->lpVtbl -> ExtractFilesFromMergeModule(This,pMergeModule,bstrDirToExtract)


#define IBuildNeo_BuildClickOnce(This)	\
    (This)->lpVtbl -> BuildClickOnce(This)

#define IBuildNeo_InitClickOnce(This,pProject,bstrConfiguration)	\
    (This)->lpVtbl -> InitClickOnce(This,pProject,bstrConfiguration)


#define IBuildNeo_BuildVirtualPackage(This,pUnkSrcProject)	\
    (This)->lpVtbl -> BuildVirtualPackage(This,pUnkSrcProject)


#define IBuildNeo_get_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> get_ProductVersion(This,bstrVersion)

#define IBuildNeo_put_ProductVersion(This,bstrVersion)	\
    (This)->lpVtbl -> put_ProductVersion(This,bstrVersion)

#define IBuildNeo_get_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> get_MSIPropertyOverride(This,bstrTok,bstrVal)

#define IBuildNeo_put_MSIPropertyOverride(This,bstrTok,bstrVal)	\
    (This)->lpVtbl -> put_MSIPropertyOverride(This,bstrTok,bstrVal)


#define IBuildNeo_put_BuildClientType(This,newVal)	\
    (This)->lpVtbl -> put_BuildClientType(This,newVal)


#define IBuildNeo_BuildFragmentUnitTest(This,pUnkSrcProject)	\
    (This)->lpVtbl -> BuildFragmentUnitTest(This,pUnkSrcProject)

#define IBuildNeo_BuildSuiteProject(This,pUnkSrcProject,bstrRelease)	\
    (This)->lpVtbl -> BuildSuiteProject(This,pUnkSrcProject,bstrRelease)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBuildNeo_BuildFragmentUnitTest_Proxy( 
    IBuildNeo __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject);


void __RPC_STUB IBuildNeo_BuildFragmentUnitTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBuildNeo_BuildSuiteProject_Proxy( 
    IBuildNeo __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pUnkSrcProject,
    /* [in] */ BSTR bstrRelease);


void __RPC_STUB IBuildNeo_BuildSuiteProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBuildNeo_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Build;

#ifdef __cplusplus

class DECLSPEC_UUID("7B582BDC-0E18-49aa-860E-AF26C1442D76")
Build;
#endif
#endif /* __ISWIBUILDLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
