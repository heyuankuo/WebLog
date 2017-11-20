// dllmain.h : 模块类的声明。

class CBaseBetModule : public ATL::CAtlDllModuleT< CBaseBetModule >
{
public :
	DECLARE_LIBID(LIBID_BaseBetLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BASEBET, "{1A097892-59B4-43A4-8732-548248C91143}")
};

extern class CBaseBetModule _AtlModule;
