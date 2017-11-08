#pragma once
#include "CenterSvr_i.h"

#define		CENT_TABLESUM		20

typedef struct _tagMsgInfo
{
	DWORD busy;		// TRUE--ռ�� FALSE--����
	DWORD nChairID;
	ENUM_HOG_STAT _hog;

	// ͬ�����
	HANDLE mi_hProcCtr;
	HANDLE mi_hRCtr;

}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// ���ҿ���
	LONG FindFrTable();

protected:
	// ��ʼ���ؼ����
	LONG InitCtrHandle( LONG nTableID );

	// �����ӽ���
	LONG CreateSub( LONG nTableID );

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];
};


extern DataSvr gloDataSvr;
