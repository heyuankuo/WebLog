#pragma once
#include "CenterData_i.h"

#define		CENT_TABLESUM		20  // ���������Ŀ
#define		CENT_CHAIRSUM		8	// ���������Ŀ
#define		CARD_BFFERLEN		8	// ���������

typedef struct _tagChairUsr
{
	LONG		cu_uid;					// �û�id 0��ʾ����״̬
	LONGLONG	cu_chip;				// �û�����
	LONGLONG	cu_bet;					// �û���ע
	LONGLONG	cu_grade;				// �û�������Ӯ�ɼ�
	DWORD		cards[CARD_BFFERLEN];	// �û�����
}ChairUsr, *PChairUsr;

typedef struct _tagMsgInfo
{
	DWORD			busy;		// TRUE--ռ�� FALSE--����
	LONG			nChairID;
	ENUM_HOG_STAT	_hog;	// ��ׯ״̬
	ChairUsr		mi_usrs[CENT_CHAIRSUM]; //������Ϣ
}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// ���ҿ�������
	LONG FindFrTable();

	// ��������
	void SetChair(LONG tableID, LONG chairID, LONG uid);

	// ��ȡ�����ϵ���Һ�
	LONG GetChair(LONG tableID, LONG chairID);

	// ��ɢ
	void DissltTable(LONG tableID);

	// ��ׯ
	int Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog);

	// ��ȡ��ׯ״̬
	void GetHogMsg(LONG tableID, LONG *chairID, ENUM_HOG_STAT *_hog);

	// �����ע
	void Bet(LONG tableID, LONG chairID, LONGLONG _bet);

	// ��ȡ�����ע��Ϣ
	void GetBet(LONG tableID, LONG *chairID, LONGLONG *_bet);

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];  // ������Ϣ
};


extern DataSvr gloDataSvr;
