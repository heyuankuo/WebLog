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