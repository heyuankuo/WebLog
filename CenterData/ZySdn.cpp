// ZySdn.cpp : CZySdn ��ʵ��

#include "stdafx.h"
#include "ZySdn.h"
#include "DataSvr.h"


// CZySdn

STDMETHODIMP CZySdn::CreateTable(LONG* tableID)
{
	// TODO: �ڴ����ʵ�ִ���
	*tableID = gloDataSvr.FindFrTable();
	return S_OK;
}

STDMETHODIMP CZySdn::Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.Hog(tableID, chairID, _hog);
	return S_OK;
}