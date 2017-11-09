// Hog.cpp : CHog ��ʵ��

#include "stdafx.h"
#include "Hog.h"
#include <time.h>

#define			PERHOGTIME		24000  // ��ʱ��

// CHog

// ��ȡʵ������
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
			// �����κ���
		}
	}
	return pSum;
}

// ���ɷ�Χ�ڵ��������
int CHog::GenRand( int Llimit, int Ulimit )
{
	srand((unsigned)time(NULL));
	return Llimit + rand() % ( Ulimit - Llimit );
}

/**
 * �����Ƿ�����δ���
 * @param		nextHog		[out]		��һ��Ҫ�������
 */
BOOL CHog::NextHog( int *nextHog)
{
	BOOL isOK = TRUE;
	for(int i = 0; i < m_ChairSum; ++i)
	{
		if ( HOG_NULL == m_pChairs[i].hs_hot_state &&
			TRUE == m_pChairs[i].hs_enableHog &&
			CHAIR_ENABLE == m_pChairs[i].hs_chair_enable ) // ����δ���
		{
			isOK = TRUE;
			*nextHog = i;
			return isOK;
		}
	}

	// �����������������˶��ѱ��
	isOK = FALSE;
	*nextHog = -1;
	return isOK;
}

/** 
 * ����������ѡ��
 * ����ѡ��Ľ��
 * ע�⣬�˴��޶�����Ϊ���ƣ�����Ϊ��Ч����֤�����������޶���������ӣ�
 */
int CHog::GetBanker()
{
	// ��ȡ�����
	int result = -1;
	int cursum = GetCurPSum(); // ��Ч��
	int rdsum = GenRand( 0, cursum ); // ��Ч���ڵ������
	for( int i = 0; i < cursum; )
	{
		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable) // ��Ч�û�
		{
			if ( rdsum == i ) // ����
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

// ����
int CHog::TurnHog()
{
	// �ж�
	return 0;
}

// ˢ��HogȨ��
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
	// TODO: �ڴ����ʵ�ִ���
	if ( NULL == _chairs ||
		 chairSum > 127 )// ����쳣
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
	// TODO: �ڴ����ʵ�ִ���
	BrushHogEnable(iniStat);
	return S_OK;
}

/**
 * ��δ���У�next ���� -1
 */
STDMETHODIMP CHog::GenerateHog(BOOL *next, LONG *_hogID)
{
	// TODO: �ڴ����ʵ�ִ���
	int nextID = 0;
	BOOL hasNext = NextHog( &nextID);
	if ( TRUE == hasNext) // ����δ����û�
	{
		*next = hasNext;
		*_hogID = nextID;
	}
	else // ����hogID������
	{
		*_hogID = GetBanker();
		m_table->ti_hog = *_hogID;
		*next	= FALSE;
	}	
	return S_OK;
}
