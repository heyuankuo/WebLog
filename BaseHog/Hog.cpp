// Hog.cpp : CHog 的实现

#include "stdafx.h"
#include "Hog.h"
#include <time.h>

#define			PERHOGTIME		24000  // 定时器

// CHog

// 获取实际数量
int CHog::GetCurPSum()
{
	int pSum = 0;
	for(int i = 0; i < m_ChairSum; ++i)
	{
		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable)
		{
			++pSum;
		}
		else
		{
			// 不做任何事
		}
	}
	return pSum;
}

// 生成范围内的随机整数
int CHog::GenRand( int Llimit, int Ulimit )
{
	srand((unsigned)time(NULL));
	return Llimit + rand() % ( Ulimit - Llimit );
}

/**
 * 查找是否还有人未表决
 * @param		nextHog		[out]		下一个要表决的人
 */
BOOL CHog::NextHog( int *nextHog)
{
	BOOL isOK = TRUE;
	for(int i = 0; i < m_ChairSum; ++i)
	{
		if ( HOG_NULL == m_pChairs[i].hs_hot_state &&
			TRUE == m_pChairs[i].hs_enableHog &&
			CHAIR_ENABLE == m_pChairs[i].hs_chair_enable ) // 有人未表决
		{
			isOK = TRUE;
			*nextHog = i;
			return isOK;
		}
	}

	// 如果允许到这里，则所有人都已表决
	isOK = FALSE;
	*nextHog = -1;
	return isOK;
}

// 间断数组随机选择函数
int CHog::GetBanker()
{
	// 获取随机数
	int cursum = GetCurPSum();
	int rdsum = GenRand( 0, cursum );
	for( int i = 0; i < cursum; )
	{
		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable) // 有效用户
		{
			if ( rdsum == i ) // 命中
			{
				
			}
			else
			{
				++i;
			}
		}
		else
		{
			continue;
		}
	}
	return 0;
}

// 轮抢
int CHog::TurnHog()
{
	// 判断
	return 0;
}

// 刷新Hog权限
int CHog::BrushHogEnable( ENUM_HOG_STAT iniStat )
{
	for( int i = 0; i < m_ChairSum; ++i)
	{
		if ( m_pChairs[i].hs_chip < m_table->ti_lowScore )
		{
			m_pChairs[i].hs_enableHog = FALSE;
		}
		else
		{
			m_pChairs[i].hs_enableHog = TRUE;
		}

		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable)
		{
			m_pChairs[i].hs_hot_state = iniStat;
		}
		else
		{
			m_pChairs[i].hs_hot_state = HOG_DOWN;
		}
	}
	return 0;
}

STDMETHODIMP CHog::BindHogData(PTableInfo _table, PChairInfo _chairs, LONG chairSum, LONG proCtr)
{
	// TODO: 在此添加实现代码
	if ( NULL == _chairs ||
		 chairSum > 127 )// 入参异常
	{
		return E_POINTER;
	}
	m_table = _table;
	m_pChairs = _chairs;
	m_ChairSum = chairSum;
	m_hProCtr = (HANDLE)proCtr;
	return S_OK;
}


STDMETHODIMP CHog::InitHogData(ENUM_HOG_STAT iniStat)
{
	// TODO: 在此添加实现代码
	BrushHogEnable(iniStat);
	return S_OK;
}


STDMETHODIMP CHog::WaitForHog(ENUM_HOG_STAT _hog, DWORD nChairID)
{
	// TODO: 在此添加实现代码
	for ( ;; )
	{
		if ( CHAIR_DISABLE == m_pChairs[nChairID].hs_chair_enable ) // 有效
		{
			m_pChairs[nChairID].hs_hot_state = _hog;

			int nextID = 0;
			BOOL hasNext = NextHog( &nextID);
			if ( TRUE == hasNext) // 继续等待
			{
				continue;
			}
			else // 开始计算hogID
			{
				break;
			}
			
		}
		else // 无效 
		{
			// 什么也不做
			continue;
		}
	}
	return S_OK;
}
