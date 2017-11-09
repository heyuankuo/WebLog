// ZySdn.h : CZySdn ������

#pragma once
#include "resource.h"       // ������



#include "CenterData_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CZySdn

class ATL_NO_VTABLE CZySdn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZySdn, &CLSID_ZySdn>,
	public IDispatchImpl<IZySdn, &IID_IZySdn, &LIBID_CenterDataLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CZySdn()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ZYSDN)


BEGIN_COM_MAP(CZySdn)
	COM_INTERFACE_ENTRY(IZySdn)
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
	

public:

	STDMETHOD(CreateTable)(LONG* tableID);
	STDMETHOD(Hog)( LONG tableID, LONG chairID, ENUM_HOG_STAT _hog);
};

OBJECT_ENTRY_AUTO(__uuidof(ZySdn), CZySdn)
