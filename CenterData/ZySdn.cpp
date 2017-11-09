// ZySdn.cpp : CZySdn 的实现

#include "stdafx.h"
#include "ZySdn.h"


// CZySdn


// 查找空闲的座子
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
