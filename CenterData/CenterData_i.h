

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Nov 09 11:13:59 2017
 */
/* Compiler settings for CenterData.idl:
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

#ifndef __CenterData_i_h__
#define __CenterData_i_h__

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
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CenterData_0000_0000 */
/* [local] */ 

typedef 
enum chair_enable
    {	CHAIR_DISABLE	= 0,
	CHAIR_ENABLE	= ( CHAIR_DISABLE + 1 ) 
    } 	ENUM_CHAIR_ENABLE;

typedef 
enum hog_stat
    {	HOG_NULL	= 0,
	HOG_DOWN	= ( HOG_NULL + 1 ) ,
	HOG_UP	= ( HOG_DOWN + 1 ) 
    } 	ENUM_HOG_STAT;

typedef 
enum player_role
    {	ROLE_ZHUANG	= 0,
	ROLE_XIAN	= ( ROLE_ZHUANG + 1 ) 
    } 	ENUM_PLAYER_ROLE;

typedef struct _tagChairInfo
    {
    ENUM_CHAIR_ENABLE hs_chair_enable;
    ENUM_HOG_STAT hs_hot_state;
    ENUM_PLAYER_ROLE hs_role;
    LONGLONG hs_chip;
    DWORD hs_enableHog;
    } 	ChairInfo;

typedef struct _tagChairInfo *PChairInfo;

typedef struct _tagTableInfo
    {
    DWORD ti_curCount;
    DWORD ti_allCount;
    LONGLONG ti_lowScore;
    } 	TableInfo;

typedef struct _tagTableInfo *PTableInfo;



extern RPC_IF_HANDLE __MIDL_itf_CenterData_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CenterData_0000_0000_v0_0_s_ifspec;

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
    };
    
#else 	/* C style interface */

    typedef struct IZySdnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZySdn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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


