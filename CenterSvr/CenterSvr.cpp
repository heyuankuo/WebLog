// CenterSvr.cpp : WinMain µÄÊµÏÖ


#include "stdafx.h"
#include "resource.h"
#include "CenterSvr_i.h"



class CCenterSvrModule : public ATL::CAtlExeModuleT< CCenterSvrModule >
	{
public :
	DECLARE_LIBID(LIBID_CenterSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CENTERSVR, "{16DCBF4E-3CC9-4CCD-9E88-B63D3476D242}")
	};

CCenterSvrModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

