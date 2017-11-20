

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "BaseBet_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _BaseBet_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } BaseBet_MIDL_TYPE_FORMAT_STRING;

typedef struct _BaseBet_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } BaseBet_MIDL_PROC_FORMAT_STRING;

typedef struct _BaseBet_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } BaseBet_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const BaseBet_MIDL_TYPE_FORMAT_STRING BaseBet__MIDL_TypeFormatString;
extern const BaseBet_MIDL_PROC_FORMAT_STRING BaseBet__MIDL_ProcFormatString;
extern const BaseBet_MIDL_EXPR_FORMAT_STRING BaseBet__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITESTIFACE_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITESTIFACE_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const BaseBet_MIDL_PROC_FORMAT_STRING BaseBet__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const BaseBet_MIDL_TYPE_FORMAT_STRING BaseBet__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ITESTIFACE, ver. 0.0,
   GUID={0xCE2EDD49,0x8C62,0x49FD,{0x82,0xA6,0x74,0xD0,0x15,0x24,0x06,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short ITESTIFACE_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ITESTIFACE_ProxyInfo =
    {
    &Object_StubDesc,
    BaseBet__MIDL_ProcFormatString.Format,
    &ITESTIFACE_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITESTIFACE_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    BaseBet__MIDL_ProcFormatString.Format,
    &ITESTIFACE_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ITESTIFACEProxyVtbl = 
{
    0,
    &IID_ITESTIFACE,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ITESTIFACE_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ITESTIFACEStubVtbl =
{
    &IID_ITESTIFACE,
    &ITESTIFACE_ServerInfo,
    7,
    &ITESTIFACE_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    BaseBet__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _BaseBet_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ITESTIFACEProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _BaseBet_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ITESTIFACEStubVtbl,
    0
};

PCInterfaceName const _BaseBet_InterfaceNamesList[] = 
{
    "ITESTIFACE",
    0
};

const IID *  const _BaseBet_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _BaseBet_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _BaseBet, pIID, n)

int __stdcall _BaseBet_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_BaseBet_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo BaseBet_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _BaseBet_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _BaseBet_StubVtblList,
    (const PCInterfaceName * ) & _BaseBet_InterfaceNamesList,
    (const IID ** ) & _BaseBet_BaseIIDList,
    & _BaseBet_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

