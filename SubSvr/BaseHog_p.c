

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Nov 12 15:12:49 2017
 */
/* Compiler settings for ..\comdata\BaseHog.idl:
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


#include "BaseHog_h.h"

#define TYPE_FORMAT_STRING_SIZE   47                                
#define PROC_FORMAT_STRING_SIZE   133                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _BaseHog_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } BaseHog_MIDL_TYPE_FORMAT_STRING;

typedef struct _BaseHog_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } BaseHog_MIDL_PROC_FORMAT_STRING;

typedef struct _BaseHog_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } BaseHog_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const BaseHog_MIDL_TYPE_FORMAT_STRING BaseHog__MIDL_TypeFormatString;
extern const BaseHog_MIDL_PROC_FORMAT_STRING BaseHog__MIDL_ProcFormatString;
extern const BaseHog_MIDL_EXPR_FORMAT_STRING BaseHog__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHog_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHog_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const BaseHog_MIDL_PROC_FORMAT_STRING BaseHog__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure BindHogData */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter _table */

/* 26 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter _chairs */

/* 32 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter chairSum */

/* 38 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 44 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 46 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitHogData */

/* 50 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 52 */	NdrFcLong( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x8 ),	/* 8 */
/* 58 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 60 */	NdrFcShort( 0x6 ),	/* 6 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 66 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter iniStat */

/* 76 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 78 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 80 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 82 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 84 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 86 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GenerateHog */

/* 88 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x9 ),	/* 9 */
/* 96 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x40 ),	/* 64 */
/* 102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter next */

/* 114 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 116 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _hogID */

/* 120 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 122 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const BaseHog_MIDL_TYPE_FORMAT_STRING BaseHog__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/*  8 */	NdrFcShort( 0x20 ),	/* 32 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* Offset= 0 (12) */
/* 14 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 16 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 18 */	0xb,		/* FC_HYPER */
			0x8,		/* FC_LONG */
/* 20 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 22 */	
			0x11, 0x0,	/* FC_RP */
/* 24 */	NdrFcShort( 0x2 ),	/* Offset= 2 (26) */
/* 26 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 28 */	NdrFcShort( 0x20 ),	/* 32 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x0 ),	/* Offset= 0 (32) */
/* 34 */	0x8,		/* FC_LONG */
			0xd,		/* FC_ENUM16 */
/* 36 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 38 */	0xb,		/* FC_HYPER */
			0x8,		/* FC_LONG */
/* 40 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 42 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 44 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHog, ver. 0.0,
   GUID={0xFA6B316E,0xBAC1,0x4360,{0xA8,0x94,0x77,0x83,0xB7,0xDF,0x34,0x0F}} */

#pragma code_seg(".orpc")
static const unsigned short IHog_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    50,
    88
    };

static const MIDL_STUBLESS_PROXY_INFO IHog_ProxyInfo =
    {
    &Object_StubDesc,
    BaseHog__MIDL_ProcFormatString.Format,
    &IHog_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHog_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    BaseHog__MIDL_ProcFormatString.Format,
    &IHog_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHogProxyVtbl = 
{
    &IHog_ProxyInfo,
    &IID_IHog,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IHog::BindHogData */ ,
    (void *) (INT_PTR) -1 /* IHog::InitHogData */ ,
    (void *) (INT_PTR) -1 /* IHog::GenerateHog */
};


static const PRPC_STUB_FUNCTION IHog_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHogStubVtbl =
{
    &IID_IHog,
    &IHog_ServerInfo,
    10,
    &IHog_table[-3],
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
    BaseHog__MIDL_TypeFormatString.Format,
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

const CInterfaceProxyVtbl * const _BaseHog_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHogProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _BaseHog_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHogStubVtbl,
    0
};

PCInterfaceName const _BaseHog_InterfaceNamesList[] = 
{
    "IHog",
    0
};

const IID *  const _BaseHog_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _BaseHog_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _BaseHog, pIID, n)

int __stdcall _BaseHog_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_BaseHog_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo BaseHog_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _BaseHog_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _BaseHog_StubVtblList,
    (const PCInterfaceName * ) & _BaseHog_InterfaceNamesList,
    (const IID ** ) & _BaseHog_BaseIIDList,
    & _BaseHog_IID_Lookup, 
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

