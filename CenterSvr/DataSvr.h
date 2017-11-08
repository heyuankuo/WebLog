#pragma once
#include "CenterSvr_i.h"

#define		CENT_TABLESUM		20

typedef struct _tagMsgInfo
{
	DWORD busy;		// TRUE--占用 FALSE--空闲
	DWORD nChairID;
	ENUM_HOG_STAT _hog;

	// 同步句柄
	HANDLE mi_hProcCtr;
	HANDLE mi_hRCtr;

}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// 查找空闲
	LONG FindFrTable();

protected:
	// 初始化控件句柄
	LONG InitCtrHandle( LONG nTableID );

	// 创建子进程
	LONG CreateSub( LONG nTableID );

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];
};


extern DataSvr gloDataSvr;
