// ZySdn.cpp : CZySdn ��ʵ��

#include "stdafx.h"
#include "ZySdn.h"


// CZySdn


// ���ҿ��е�����
LONG CZySdn::FindFrTable()
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
