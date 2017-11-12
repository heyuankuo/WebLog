

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Nov 12 15:12:51 2017
 */
/* Compiler settings for ..\comdata\CenterData.idl:
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

#ifndef __CenterData_h_h__
#define __CenterData_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IZySdn_FWD_DEFINED__
#define __IZySdn_FWD_DEFINED__
typedef interface IZySdn IZySdn;

#endif 	/* __IZySdn_FWD_DEFINED__ */


#ifndef __ZySdn_FWD_DEFINED__
#define __ZySdn_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZySdn ZySdn;
#else
typedef struct ZySdn ZySdn;
#endif /* __cplusplus */

#endif 	/* __ZySdn_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GameData.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IZySdn_INTERFACE_DEFINED__
#define __IZySdn_INTERFACE_DEFINED__

/* interface IZySdn */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZySdn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59D8A9ED-F59B-445C-9685-22CD38469884")
    IZySdn : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateTable( 
            /* [retval][out] */ LONG *tableID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Hog( 
            /* [in] */ LONG tableID,
            /* [in] */ LONG chairID,
            /* [in] */ ENUM_HOG_STAT _hog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetChair( 
            /* [in] */ LONG tableId,
            /* [in] */ LONG chairId,
            /* [in] */ LONG uid) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetChair( 
            /* [in] */ LONG tableID,
            /* [in] */ LONG chairId,
            /* [retval][out] */ LONG *uid) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DissltTable( 
            /* [in] */ LONG tableId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetHogMsg( 
            /* [in] */ LONG talbeId,
            /* [out] */ LONG *chairId,
            /* [out] */ ENUM_HOG_STAT *_hogSlu) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IZySdnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZySdn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZySdn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZySdn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZySdn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZySdn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZySdn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZySdn * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateTable )( 
            IZySdn * This,
            /* [retval][out] */ LONG *tableID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Hog )( 
            IZySdn * This,
            /* [in] */ LONG tableID,
            /* [in] */ LONG chairID,
            /* [in] */ ENUM_HOG_STAT _hog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetChair )( 
            IZySdn * This,
            /* [in] */ LONG tableId,
            /* [in] */ LONG chairId,
            /* [in] */ LONG uid);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetChair )( 
            IZySdn * This,
            /* [in] */ LONG tableID,
            /* [in] */ LONG chairId,
            /* [retval][out] */ LONG *uid);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DissltTable )( 
            IZySdn * This,
            /* [in] */ LONG tableId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetHogMsg )( 
            IZySdn * This,
            /* [in] */ LONG talbeId,
            /* [out] */ LONG *chairId,
            /* [out] */ ENUM_HOG_STAT *_hogSlu);
        
        END_INTERFACE
    } IZySdnVtbl;

    interface IZySdn
    {
        CONST_VTBL struct IZySdnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZySdn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZySdn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZySdn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZySdn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZySdn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZySdn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZySdn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IZySdn_CreateTable(This,tableID)	\
    ( (This)->lpVtbl -> CreateTable(This,tableID) ) 

#define IZySdn_Hog(This,tableID,chairID,_hog)	\
    ( (This)->lpVtbl -> Hog(This,tableID,chairID,_hog) ) 

#define IZySdn_SetChair(This,tableId,chairId,uid)	\
    ( (This)->lpVtbl -> SetChair(This,tableId,chairId,uid) ) 

#define IZySdn_GetChair(This,tableID,chairId,uid)	\
    ( (This)->lpVtbl -> GetChair(This,tableID,chairId,uid) ) 

#define IZySdn_DissltTable(This,tableId)	\
    ( (This)->lpVtbl -> DissltTable(This,tableId) ) 

#define IZySdn_GetHogMsg(This,talbeId,chairId,_hogSlu)	\
    ( (This)->lpVtbl -> GetHogMsg(This,talbeId,chairId,_hogSlu) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZySdn_INTERFACE_DEFINED__ */



#ifndef __CenterDataLib_LIBRARY_DEFINED__
#define __CenterDataLib_LIBRARY_DEFINED__

/* library CenterDataLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CenterDataLib;

EXTERN_C const CLSID CLSID_ZySdn;

#ifdef __cplusplus

class DECLSPEC_UUID("EA23FE32-4B93-478B-B2A8-7681BFA1EEB2")
ZySdn;
#endif
#endif /* __CenterDataLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


