#include "StdAfx.h"
#include "DataSvr.h"
#define			PRO_PATH		L"E:\\project\\VC++\\WebLog\\SubSvr\\x64\\Debug\\SubSvr.exe"

DataSvr::DataSvr(void)
{
}


DataSvr::~DataSvr(void)
{
}

// 初始化控件句柄
LONG DataSvr::InitCtrHandle( LONG nTableID )
{
	// 初始化句柄状态
	SECURITY_ATTRIBUTES sa = {0};
	sa.nLength = sizeof sa;
	sa.bInheritHandle = TRUE;
	m_gMsg[nTableID].mi_hProcCtr	= ::CreateEvent( &sa, TRUE, FALSE, NULL);
	m_gMsg[nTableID].mi_hRCtr		= ::CreateEvent( &sa, TRUE, FALSE, NULL);

	return 0;
}

// 创建子进程
LONG DataSvr::CreateSub( LONG nTableID )
{
	// 构造需要被传出的句柄
	InitCtrHandle( nTableID );

	// 构造命令行
	wchar_t wcsCommandLine[64] = {0};
	swprintf_s( wcsCommandLine, sizeof wcsCommandLine / sizeof(wchar_t), 
		L"mi_hProcCtr:%lld,mi_hRCtr:%lld,mi_tID:%ld", (LONGLONG)m_gMsg[nTableID].mi_hProcCtr, (LONGLONG)m_gMsg[nTableID].mi_hRCtr, nTableID );
	// 设置显示
	STARTUPINFO si = {0}; 
	si.cb = sizeof si;
	// si.wShowWindow = ;
	PROCESS_INFORMATION pi = {0};  
   
    ::CreateProcess(	PRO_PATH,
						wcsCommandLine,
						NULL, NULL, 
						TRUE,	// 可继承 
						0, NULL, NULL, 
						&si, 
						&pi) ; 
	return 0;
}

// 前进一步
void DataSvr::StepThrough( LONG nTableID )
{
	::WaitForSingleObject( m_gMsg[nTableID].mi_hRCtr, INFINITE );
	::ResetEvent(m_gMsg[nTableID].mi_hRCtr);
	::SetEvent(m_gMsg[nTableID].mi_hProcCtr);

	::WaitForSingleObject( m_gMsg[nTableID].mi_hRCtr, INFINITE );
}

// 解散桌子
void DataSvr::DissltTable(LONG tableId)
{
	StepThrough(tableId);
	::CloseHandle(m_gMsg[tableId].mi_hRCtr);
	::CloseHandle(m_gMsg[tableId].mi_hProcCtr);
	m_gMsg[tableId].mi_hRCtr	= NULL;
	m_gMsg[tableId].mi_hProcCtr = NULL;
}

DataSvr gloDataSvr;