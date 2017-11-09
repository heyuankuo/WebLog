#pragma once
#include "CenterData_i.h"

#define		CENT_TABLESUM		20
typedef struct _tagMsgInfo
{
	DWORD busy;		// TRUE--’º”√ FALSE--ø’œ–
	LONG nChairID;
	ENUM_HOG_STAT _hog;

}MsgInfo, *PMsgInfo;

class DataSvr
{
public:
	DataSvr(void);
	~DataSvr(void);

public:
	// ≤È’“ø’œ–
	LONG FindFrTable();

	// Hog
	int Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog);

protected:
	MsgInfo m_gMsg[CENT_TABLESUM];
};


extern DataSvr gloDataSvr;
