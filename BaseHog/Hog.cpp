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

/** 
 * 间断数据随机选择
 * 返回选择的结果
 * 注意，此处限定条件为估计（即仅为有效性验证，若有其他限定，自行添加）
 */
int CHog::GetBanker()
{
	// 获取随机数
	int result = -1;
	int cursum = GetCurPSum(); // 有效数
	int rdsum = GenRand( 0, cursum ); // 有效数内的随机数
	for( int i = 0; i < cursum; )
	{
		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable) // 有效用户
		{
			if ( rdsum == i ) // 命中
			{
				result = i;
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

	return result;
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

STDMETHODIMP CHog::BindHogData(PTableInfo _table, PChairInfo _chairs, LONG chairSum)
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
	return S_OK;
}

STDMETHODIMP CHog::InitHogData(ENUM_HOG_STAT iniStat)
{
	// TODO: 在此添加实现代码
	BrushHogEnable(iniStat);
	return S_OK;
}

/**
 * 若未命中，next 返回 -1
 */
STDMETHODIMP CHog::GenerateHog(BOOL *next, LONG *_hogID)
{
	// TODO: 在此添加实现代码
	int nextID = 0;
	BOOL hasNext = NextHog( &nextID);
	if ( TRUE == hasNext) // 返回未表决用户
	{
		*next = hasNext;
		*_hogID = nextID;
	}
	else // 计算hogID并返回
	{
		*_hogID = GetBanker();
		m_table->ti_hog = *_hogID;
		*next	= FALSE;
	}	
	return S_OK;
}
