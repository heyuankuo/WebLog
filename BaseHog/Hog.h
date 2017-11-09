// Hog.h : CHog ������

#pragma once
#include "resource.h"       // ������



#include "BaseHog_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
	// ��ȡʵ������
	int GetCurPSum();

	// ���ɷ�Χ�ڵ��������
	int GenRand( int Llimit, int Ulimit );

	// �ж������˶��ѱ��
	BOOL NextHog( int *nextHog );

	// ����������ѡ����
	int GetBanker();

	// ����
	int TurnHog();

	// ˢ��HogȨ��
	int BrushHogEnable( ENUM_HOG_STAT iniStat );

public:


	// ������
	STDMETHOD(BindHogData)(PTableInfo _table, PChairInfo _chairs, LONG chairSum);

	// ��ʼ������
	STDMETHOD(InitHogData)(ENUM_HOG_STAT iniStat);
	STDMETHOD(GenerateHog)(BOOL *next, LONG *_hogID);
};

OBJECT_ENTRY_AUTO(__uuidof(Hog), CHog)
