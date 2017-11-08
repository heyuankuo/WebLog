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

// ����������ѡ����
int CHog::GetBanker()
{
	// ��ȡ�����
	int cursum = GetCurPSum();
	int rdsum = GenRand( 0, cursum );
	for( int i = 0; i < cursum; )
	{
		if ( CHAIR_ENABLE == m_pChairs[i].hs_chair_enable) // ��Ч�û�
		{
			if ( rdsum == i ) // ����
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

STDMETHODIMP CHog::BindHogData(PTableInfo _table, PChairInfo _chairs, LONG chairSum, LONG proCtr)
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
	m_hProCtr = (HANDLE)proCtr;
	return S_OK;
}


STDMETHODIMP CHog::InitHogData(ENUM_HOG_STAT iniStat)
{
	// TODO: �ڴ����ʵ�ִ���
	BrushHogEnable(iniStat);
	return S_OK;
}


STDMETHODIMP CHog::WaitForHog(ENUM_HOG_STAT _hog, DWORD nChairID)
{
	// TODO: �ڴ����ʵ�ִ���
	for ( ;; )
	{
		if ( CHAIR_DISABLE == m_pChairs[nChairID].hs_chair_enable ) // ��Ч
		{
			m_pChairs[nChairID].hs_hot_state = _hog;

			int nextID = 0;
			BOOL hasNext = NextHog( &nextID);
			if ( TRUE == hasNext) // �����ȴ�
			{
				continue;
			}
			else // ��ʼ����hogID
			{
				break;
			}
			
		}
		else // ��Ч 
		{
			// ʲôҲ����
			continue;
		}
	}
	return S_OK;
}
