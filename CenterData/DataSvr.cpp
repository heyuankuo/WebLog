#include "StdAfx.h"
#include "DataSvr.h"

DataSvr::DataSvr(void)
{
	memset( m_gMsg, 0, sizeof (MsgInfo) * CENT_TABLESUM);
}


DataSvr::~DataSvr(void)
{
}

// ²éÕÒ¿ÕÏÐµÄ×ù×Ó
LONG DataSvr::FindFrTable()
{
	LONG tableID = -1;
	for( int i = 0; i < CENT_TABLESUM; ++i)
	{
		if ( FALSE == m_gMsg[i].busy )
		{
			m_gMsg[i].busy = TRUE;
			tableID = i;
		}
	}

	return tableID;
}

// Hog
int DataSvr::Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog)
{
	m_gMsg[tableID].nChairID = chairID;
	m_gMsg[tableID]._hog = _hog;

	return 0;
}

DataSvr gloDataSvr;