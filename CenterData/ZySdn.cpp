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

STDMETHODIMP CZySdn::SetChair(LONG tableId, LONG chairId, LONG uid)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.SetChair(tableId, chairId, uid);
	return S_OK;
}


STDMETHODIMP CZySdn::GetChair(LONG tableID, LONG chairId, LONG* uid)
{
	// TODO: �ڴ����ʵ�ִ���
	*uid = gloDataSvr.GetChair(tableID, chairId);
	return S_OK;
}

// ��ɢ
STDMETHODIMP CZySdn::DissltTable(LONG tableId)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.DissltTable(tableId);
	return S_OK;
}


STDMETHODIMP CZySdn::GetHogMsg(LONG talbeId, LONG * chairId, ENUM_HOG_STAT* _hogSlu)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.GetHogMsg(talbeId, chairId, _hogSlu);
	return S_OK;
}
