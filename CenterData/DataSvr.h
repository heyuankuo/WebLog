#pragma once
#include "CenterData_i.h"

#define		CENT_TABLESUM		20  // 最大桌子数目
#define		CENT_CHAIRSUM		8	// 最大椅子数目
#define		CARD_BFFERLEN		8	// 最大手牌数

typedef struct _tagChairUsr
{
	LONG		cu_uid;					// 用户id 0表示空闲状态
	LONGLONG	cu_chip;				// 用户筹码
	LONGLONG	cu_bet;					// 用户下注
	LONGLONG	cu_grade;				// 用户单局输赢成绩
	DWORD		cards[CARD_BFFERLEN];	// 用户手牌
}ChairUsr, *PChairUsr;

typedef struct _tagMsgInfo
{
	DWORD			busy;		// TRUE--占用 FALSE--空闲
	LONG			nChairID;
	ENUM_HOG_STAT	_hog;	// 叫庄状态
	ChairUsr		mi_usrs[CENT_CHAIRSUM]; //椅子信息
}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// 查找空闲桌子
	LONG FindFrTable();

	// 设置椅子
	void SetChair(LONG tableID, LONG chairID, LONG uid);

	// 获取椅子上的玩家号
	LONG GetChair(LONG tableID, LONG chairID);

	// 解散
	void DissltTable(LONG tableID);

	// 叫庄
	int Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog);

	// 获取叫庄状态
	void GetHogMsg(LONG tableID, LONG *chairID, ENUM_HOG_STAT *_hog);

	// 玩家下注
	void Bet(LONG tableID, LONG chairID, LONGLONG _bet);

	// 获取玩家下注信息
	void GetBet(LONG tableID, LONG *chairID, LONGLONG *_bet);

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];  // 桌子信息
};


extern DataSvr gloDataSvr;
