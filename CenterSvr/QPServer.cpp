// QPServer.cpp : CQPServer 的实现

#include "stdafx.h"
#include "QPServer.h"

#include "DataSvr.h"

// CQPServer



STDMETHODIMP CQPServer::Hog(LONG nTableID, LONG nChairID, ENUM_HOG_STAT _hog)
{
	// TODO: 在此添加实现代码
	
	return S_OK;
}


STDMETHODIMP CQPServer::CreateSub(LONG subType, LONG* tid)
{
	// TODO: 在此添加实现代码
	*tid = gloDataSvr.FindFrTable(); // 查询空余桌子

	return S_OK;
}
