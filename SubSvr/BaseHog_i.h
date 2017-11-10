

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Nov 10 08:58:58 2017
 */
/* Compiler settings for BaseHog.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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

#ifndef __BaseHog_i_h__
#define __BaseHog_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHog_FWD_DEFINED__
#define __IHog_FWD_DEFINED__
typedef interface IHog IHog;
#endif 	/* __IHog_FWD_DEFINED__ */


#ifndef __Hog_FWD_DEFINED__
#define __Hog_FWD_DEFINED__

#ifdef __cplusplus
typedef class Hog Hog;
#else
typedef struct Hog Hog;
#endif /* __cplusplus */

#endif 	/* __Hog_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GameData.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IHog_INTERFACE_DEFINED__
#define __IHog_INTERFACE_DEFINED__

/* interface IHog */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA6B316E-BAC1-4360-A894-7783B7DF340F")
    IHog : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BindHogData( 
            /* [in] */ PTableInfo _table,
            /* [in] */ PChairInfo _chairs,
            /* [in] */ LONG chairSum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitHogData( 
            /* [in] */ ENUM_HOG_STAT iniStat) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GenerateHog( 
            /* [out] */ BOOL *next,
            /* [out] */ LONG *_hogID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BindHogData )( 
            IHog * This,
            /* [in] */ PTableInfo _table,
            /* [in] */ PChairInfo _chairs,
            /* [in] */ LONG chairSum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitHogData )( 
            IHog * This,
            /* [in] */ ENUM_HOG_STAT iniStat);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GenerateHog )( 
            IHog * This,
            /* [out] */ BOOL *next,
            /* [out] */ LONG *_hogID);
        
        END_INTERFACE
    } IHogVtbl;

    interface IHog
    {
        CONST_VTBL struct IHogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHog_BindHogData(This,_table,_chairs,chairSum)	\
    ( (This)->lpVtbl -> BindHogData(This,_table,_chairs,chairSum) ) 

#define IHog_InitHogData(This,iniStat)	\
    ( (This)->lpVtbl -> InitHogData(This,iniStat) ) 

#define IHog_GenerateHog(This,next,_hogID)	\
    ( (This)->lpVtbl -> GenerateHog(This,next,_hogID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHog_INTERFACE_DEFINED__ */



#ifndef __BaseHogLib_LIBRARY_DEFINED__
#define __BaseHogLib_LIBRARY_DEFINED__

/* library BaseHogLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_BaseHogLib;

EXTERN_C const CLSID CLSID_Hog;

#ifdef __cplusplus

class DECLSPEC_UUID("4E14A166-5C2E-412F-A94B-326FF50A7A59")
Hog;
#endif
#endif /* __BaseHogLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


