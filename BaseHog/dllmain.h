// dllmain.h : 模块类的声明。

class CBaseHogModule : public ATL::CAtlDllModuleT< CBaseHogModule >
{
public :
	DECLARE_LIBID(LIBID_BaseHogLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BASEHOG, "{A9E8F431-E825-43E0-8F83-57ED072542FB}")
};

extern class CBaseHogModule _AtlModule;
