

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Nov 12 15:12:52 2017
 */
/* Compiler settings for ..\comdata\GameData.idl:
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


#ifndef __GameData_h__
#define __GameData_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_GameData_0000_0000 */
/* [local] */ 

typedef 
enum chair_enable
    {
        CHAIR_DISABLE	= 0,
        CHAIR_ENABLE	= ( CHAIR_DISABLE + 1 ) 
    } 	ENUM_CHAIR_ENABLE;

typedef 
enum hog_stat
    {
        HOG_NULL	= 0,
        HOG_DOWN	= ( HOG_NULL + 1 ) ,
        HOG_UP	= ( HOG_DOWN + 1 ) 
    } 	ENUM_HOG_STAT;

typedef 
enum player_role
    {
        ROLE_ZHUANG	= 0,
        ROLE_XIAN	= ( ROLE_ZHUANG + 1 ) 
    } 	ENUM_PLAYER_ROLE;

typedef struct _tagChairInfo
    {
    LONG hs_uid;
    ENUM_CHAIR_ENABLE hs_chair_enable;
    ENUM_HOG_STAT hs_hot_state;
    ENUM_PLAYER_ROLE hs_role;
    LONGLONG hs_chip;
    DWORD hs_enableHog;
    } 	ChairInfo;

typedef struct _tagChairInfo *PChairInfo;

typedef struct _tagTableInfo
    {
    DWORD ti_tID;
    DWORD ti_curCount;
    DWORD ti_allCount;
    LONGLONG ti_lowScore;
    DWORD ti_hog;
    } 	TableInfo;

typedef struct _tagTableInfo *PTableInfo;



extern RPC_IF_HANDLE __MIDL_itf_GameData_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GameData_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


