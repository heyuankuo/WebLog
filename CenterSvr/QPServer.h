// QPServer.h : CQPServer ������

#pragma once
#include "resource.h"       // ������



#include "CenterSvr_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CQPServer

class ATL_NO_VTABLE CQPServer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CQPServer, &CLSID_QPServer>,
	public IDispatchImpl<IQPServer, &IID_IQPServer, &LIBID_CenterSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CQPServer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_QPSERVER)


BEGIN_COM_MAP(CQPServer)
	COM_INTERFACE_ENTRY(IQPServer)
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

// msgdata
protected:	

public:



	STDMETHOD(Hog)(LONG nTableID, LONG nChairID, ENUM_HOG_STAT _hog);
	STDMETHOD(CreateSub)(LONG subType, LONG tid);
	STDMETHOD(StepThrough)(LONG nTableID);
	STDMETHOD(DissltTable)(LONG tableId);
};

OBJECT_ENTRY_AUTO(__uuidof(QPServer), CQPServer)
