// Hog.h : CHog 的声明

#pragma once
#include "resource.h"       // 主符号



#include "BaseHog_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CHog

class ATL_NO_VTABLE CHog :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHog, &CLSID_Hog>,
	public IDispatchImpl<IHog, &IID_IHog, &LIBID_BaseHogLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHog()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HOG)


BEGIN_COM_MAP(CHog)
	COM_INTERFACE_ENTRY(IHog)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

protected:
	PChairInfo	m_pChairs;
	LONG		m_ChairSum;
	HANDLE		m_hProCtr;
	PTableInfo	m_table;

protected:
	// 获取实际数量
	int GetCurPSum();

	// 生成范围内的随机整数
	int GenRand( int Llimit, int Ulimit );

	// 判断所有人都已表决
	BOOL NextHog( int *nextHog );

	// 间断数组随机选择函数
	int GetBanker();

	// 轮抢
	int TurnHog();

	// 刷新Hog权限
	int BrushHogEnable( ENUM_HOG_STAT iniStat );

public:


	// 绑定数据
	STDMETHOD(BindHogData)(PTableInfo _table, PChairInfo _chairs, LONG chairSum);

	// 初始化数据
	STDMETHOD(InitHogData)(ENUM_HOG_STAT iniStat);
	STDMETHOD(GenerateHog)(BOOL *next, LONG *_hogID);
};

OBJECT_ENTRY_AUTO(__uuidof(Hog), CHog)
