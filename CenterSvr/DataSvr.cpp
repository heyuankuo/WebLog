#include "StdAfx.h"
#include "DataSvr.h"
#define			PRO_PATH		L"E:\\project\\VC++\\EXCEL_NPOI\\Demo\\Debug\\SubSvr.exe"

DataSvr::DataSvr(void)
{
}


DataSvr::~DataSvr(void)
{
}

// ��ʼ���ؼ����
LONG DataSvr::InitCtrHandle( LONG nTableID )
{
	// ��ʼ�����״̬
	SECURITY_ATTRIBUTES sa = {0};
	sa.nLength = sizeof sa;
	sa.bInheritHandle = TRUE;
	m_gMsg[nTableID].mi_hProcCtr	= ::CreateEvent( &sa, TRUE, FALSE, NULL);
	m_gMsg[nTableID].mi_hRCtr		= ::CreateEvent( &sa, TRUE, FALSE, NULL);

	return 0;
}

// �����ӽ���
LONG DataSvr::CreateSub( LONG nTableID )
{
	// ����������
	wchar_t wcsCommandLine[64] = {0};
	swprintf_s( wcsCommandLine, sizeof wcsCommandLine / sizeof(wchar_t), 
		L"mi_hProcCtr:%ld,mi_hRCtr:%ld", m_gMsg[nTableID].mi_hProcCtr, m_gMsg[nTableID].mi_hRCtr );
	// ������ʾ
	STARTUPINFO si = {0}; 
	si.cb = sizeof si;
	PROCESS_INFORMATION pi = {0};  
   
    ::CreateProcess(	PRO_PATH,
						wcsCommandLine,
						NULL, NULL, 
						TRUE,	// �ɼ̳� 
						0, NULL, NULL, 
						&si, 
						&pi) ; 
	return 0;
}

DataSvr gloDataSvr;