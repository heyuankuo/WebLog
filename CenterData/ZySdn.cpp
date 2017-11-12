// ZySdn.cpp : CZySdn 的实现

#include "stdafx.h"
#include "ZySdn.h"
#include "DataSvr.h"


// CZySdn

STDMETHODIMP CZySdn::CreateTable(LONG* tableID)
{
	// TODO: 在此添加实现代码
	*tableID = gloDataSvr.FindFrTable();
	return S_OK;
}

STDMETHODIMP CZySdn::Hog(LONG tableID, LONG chairID, ENUM_HOG_STAT _hog)
{
	// TODO: 在此添加实现代码
	gloDataSvr.Hog(tableID, chairID, _hog);
	return S_OK;
}

STDMETHODIMP CZySdn::SetChair(LONG tableId, LONG chairId, LONG uid)
{
	// TODO: 在此添加实现代码
	gloDataSvr.SetChair(tableId, chairId, uid);
	return S_OK;
}


STDMETHODIMP CZySdn::GetChair(LONG tableID, LONG chairId, LONG* uid)
{
	// TODO: 在此添加实现代码
	*uid = gloDataSvr.GetChair(tableID, chairId);
	return S_OK;
}

// 解散
STDMETHODIMP CZySdn::DissltTable(LONG tableId)
{
	// TODO: 在此添加实现代码
	gloDataSvr.DissltTable(tableId);
	return S_OK;
}


STDMETHODIMP CZySdn::GetHogMsg(LONG talbeId, LONG * chairId, ENUM_HOG_STAT* _hogSlu)
{
	// TODO: 在此添加实现代码
	gloDataSvr.GetHogMsg(talbeId, chairId, _hogSlu);
	return S_OK;
}
