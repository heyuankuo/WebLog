#include "StdAfx.h"
#include "DataSvr.h"

DataSvr::DataSvr(void)
{
	memset( m_gMsg, 0, sizeof (MsgInfo) * CENT_TABLESUM);
}


DataSvr::~DataSvr(void)
{
}

// 查找空闲的座子
LONG DataSvr::FindFrTable()
{
	LONG tableID = -1;
	for( int i = 0; i < CENT_TABLESUM; ++i)
	{
		if ( FALSE == m_gMsg[i].busy ) //找到空闲座子
		{
			m_gMsg[i].busy = TRUE;// 初始化状态
			memset(m_gMsg[i].mi_usrs, 0, sizeof(ChairUsr)*CENT_CHAIRSUM); // 初始化椅子信息

			tableID = i;
			break;
		}
	}

	return tableID;
}

// 设置椅子
void DataSvr::SetChair(LONG tableID, LONG chairID, LONG uid)
{
	m_gMsg[tableID].mi_usrs[chairID].cu_uid = uid;
}

// 获取椅子上的玩家号
LONG DataSvr::GetChair(LONG tableID, LONG chairID)
{
	return m_gMsg[tableID].mi_usrs[chairID].cu_uid;
}

// 解散
void DataSvr::DissltTable(LONG tableID)
{
	memset(&m_gMsg[tableID], 0, sizeof(MsgInfo));
}

// Hog
int DataSvr::Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog)
{
	m_gMsg[tableID].nChairID = chairID;
	m_gMsg[tableID]._hog = _hog;

	return 0;
}

// 叫庄
void DataSvr::GetHogMsg(LONG tableID, LONG *chairID, ENUM_HOG_STAT *_hog)
{
	*chairID = m_gMsg[tableID].nChairID;
	*_hog = m_gMsg[tableID]._hog;
}

// 玩家下注
void DataSvr::Bet(LONG tableID, LONG chairID, LONGLONG _bet)
{
	m_gMsg[tableID].mi_usrs[chairID].cu_bet -= _bet;
}

// 获取玩家下注信息
void DataSvr::GetBet(LONG tableID, LONG *chairID, LONGLONG *_bet)
{
	// m_gMsg[tableID].mi_usrs[chairID].cu_bet -= _bet;
}

DataSvr gloDataSvr;