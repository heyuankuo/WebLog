#pragma once
#include "CenterSvr_i.h"

#define		CENT_TABLESUM		20

typedef struct _tagMsgInfo
{
	// ͬ�����
	HANDLE	mi_hProcCtr;
	HANDLE	mi_hRCtr;

}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// �����ӽ���
	LONG CreateSub( LONG nTableID );

protected:
	// ��ʼ���ؼ����
	LONG InitCtrHandle( LONG nTableID );

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];
};


extern DataSvr gloDataSvr;
