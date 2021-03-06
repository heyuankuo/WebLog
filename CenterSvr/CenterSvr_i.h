

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 13 13:41:10 2017
 */
/* Compiler settings for ..\comdata\CenterSvr.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __CenterSvr_i_h__
#define __CenterSvr_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IQPServer_FWD_DEFINED__
#define __IQPServer_FWD_DEFINED__
typedef interface IQPServer IQPServer;

#endif 	/* __IQPServer_FWD_DEFINED__ */


#ifndef __QPServer_FWD_DEFINED__
#define __QPServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class QPServer QPServer;
#else
typedef struct QPServer QPServer;
#endif /* __cplusplus */

#endif 	/* __QPServer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GameData.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IQPServer_INTERFACE_DEFINED__
#define __IQPServer_INTERFACE_DEFINED__

/* interface IQPServer */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IQPServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDCF44B6-3174-4D8A-B2EF-D9A159474D49")
    IQPServer : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Hog( 
            /* [in] */ LONG nTableID,
            /* [in] */ LONG nChairID,
            /* [in] */ ENUM_HOG_STAT _hog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateSub( 
            /* [in] */ LONG subType,
            /* [in] */ LONG tid) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StepThrough( 
            /* [in] */ LONG nTableID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DissltTable( 
            /* [in] */ LONG tableId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IQPServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQPServer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQPServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQPServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IQPServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IQPServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IQPServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IQPServer * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Hog )( 
            IQPServer * This,
            /* [in] */ LONG nTableID,
            /* [in] */ LONG nChairID,
            /* [in] */ ENUM_HOG_STAT _hog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateSub )( 
            IQPServer * This,
            /* [in] */ LONG subType,
            /* [in] */ LONG tid);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StepThrough )( 
            IQPServer * This,
            /* [in] */ LONG nTableID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DissltTable )( 
            IQPServer * This,
            /* [in] */ LONG tableId);
        
        END_INTERFACE
    } IQPServerVtbl;

    interface IQPServer
    {
        CONST_VTBL struct IQPServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQPServer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQPServer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQPServer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQPServer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IQPServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IQPServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IQPServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IQPServer_Hog(This,nTableID,nChairID,_hog)	\
    ( (This)->lpVtbl -> Hog(This,nTableID,nChairID,_hog) ) 

#define IQPServer_CreateSub(This,subType,tid)	\
    ( (This)->lpVtbl -> CreateSub(This,subType,tid) ) 

#define IQPServer_StepThrough(This,nTableID)	\
    ( (This)->lpVtbl -> StepThrough(This,nTableID) ) 

#define IQPServer_DissltTable(This,tableId)	\
    ( (This)->lpVtbl -> DissltTable(This,tableId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IQPServer_INTERFACE_DEFINED__ */



#ifndef __CenterSvrLib_LIBRARY_DEFINED__
#define __CenterSvrLib_LIBRARY_DEFINED__

/* library CenterSvrLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CenterSvrLib;

EXTERN_C const CLSID CLSID_QPServer;

#ifdef __cplusplus

class DECLSPEC_UUID("6370FA5B-0048-4053-B645-036909DDA673")
QPServer;
#endif
#endif /* __CenterSvrLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


