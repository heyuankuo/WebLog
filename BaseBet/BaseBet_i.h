

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 20 11:14:49 2017
 */
/* Compiler settings for BaseBet.idl:
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

#ifndef __BaseBet_i_h__
#define __BaseBet_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITESTIFACE_FWD_DEFINED__
#define __ITESTIFACE_FWD_DEFINED__
typedef interface ITESTIFACE ITESTIFACE;

#endif 	/* __ITESTIFACE_FWD_DEFINED__ */


#ifndef __TESTIFACE_FWD_DEFINED__
#define __TESTIFACE_FWD_DEFINED__

#ifdef __cplusplus
typedef class TESTIFACE TESTIFACE;
#else
typedef struct TESTIFACE TESTIFACE;
#endif /* __cplusplus */

#endif 	/* __TESTIFACE_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GameData.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITESTIFACE_INTERFACE_DEFINED__
#define __ITESTIFACE_INTERFACE_DEFINED__

/* interface ITESTIFACE */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITESTIFACE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE2EDD49-8C62-49FD-82A6-74D015240694")
    ITESTIFACE : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITESTIFACEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITESTIFACE * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITESTIFACE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITESTIFACE * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITESTIFACE * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITESTIFACE * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITESTIFACE * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITESTIFACE * This,
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
        
        END_INTERFACE
    } ITESTIFACEVtbl;

    interface ITESTIFACE
    {
        CONST_VTBL struct ITESTIFACEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITESTIFACE_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITESTIFACE_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITESTIFACE_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITESTIFACE_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITESTIFACE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITESTIFACE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITESTIFACE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITESTIFACE_INTERFACE_DEFINED__ */



#ifndef __BaseBetLib_LIBRARY_DEFINED__
#define __BaseBetLib_LIBRARY_DEFINED__

/* library BaseBetLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_BaseBetLib;

EXTERN_C const CLSID CLSID_TESTIFACE;

#ifdef __cplusplus

class DECLSPEC_UUID("18B328B0-E499-43C8-A9EB-B0C7C427AC31")
TESTIFACE;
#endif
#endif /* __BaseBetLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


