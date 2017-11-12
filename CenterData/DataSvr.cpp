#include "StdAfx.h"
#include "DataSvr.h"

DataSvr::DataSvr(void)
{
	memset( m_gMsg, 0, sizeof (MsgInfo) * CENT_TABLESUM);
}


DataSvr::~DataSvr(void)
{
}

// ���ҿ��е�����
LONG DataSvr::FindFrTable()
{
	LONG tableID = -1;
	for( int i = 0; i < CENT_TABLESUM; ++i)
	{
		if ( FALSE == m_gMsg[i].busy ) //�ҵ���������
		{
			m_gMsg[i].busy = TRUE;// ��ʼ��״̬
			memset(m_gMsg[i].mi_usrs, 0, sizeof(ChairUsr)*CENT_CHAIRSUM); // ��ʼ��������Ϣ

			tableID = i;
			break;
		}
	}

	return tableID;
}

// ��������
void DataSvr::SetChair(LONG tableID, LONG chairID, LONG uid)
{
	m_gMsg[tableID].mi_usrs[chairID].cu_uid = uid;
}

// ��ȡ�����ϵ���Һ�
LONG DataSvr::GetChair(LONG tableID, LONG chairID)
{
	return m_gMsg[tableID].mi_usrs[chairID].cu_uid;
}

// ��ɢ
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

// ��ׯ
void DataSvr::GetHogMsg(LONG tableID, LONG *chairID, ENUM_HOG_STAT *_hog)
{
	*chairID = m_gMsg[tableID].nChairID;
	*_hog = m_gMsg[tableID]._hog;
}

// �����ע
void DataSvr::Bet(LONG tableID, LONG chairID, LONGLONG _bet)
{
	m_gMsg[tableID].mi_usrs[chairID].cu_bet -= _bet;
}

// ��ȡ�����ע��Ϣ
void DataSvr::GetBet(LONG tableID, LONG *chairID, LONGLONG *_bet)
{
	// m_gMsg[tableID].mi_usrs[chairID].cu_bet -= _bet;
}

DataSvr gloDataSvr;