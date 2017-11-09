// CenterData.cpp : WinMain µÄÊµÏÖ


#include "stdafx.h"
#include "resource.h"
#include "CenterData_i.h"



class CCenterDataModule : public ATL::CAtlExeModuleT< CCenterDataModule >
	{
public :
	DECLARE_LIBID(LIBID_CenterDataLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CENTERDATA, "{E0AD5DE2-BBCE-48E6-A5D9-1E57E87A8501}")
	};

CCenterDataModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

