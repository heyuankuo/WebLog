// QPServer.cpp : CQPServer ��ʵ��

#include "stdafx.h"
#include "QPServer.h"

#include "DataSvr.h"

// CQPServer



STDMETHODIMP CQPServer::Hog(LONG nTableID, LONG nChairID, ENUM_HOG_STAT _hog)
{
	// TODO: �ڴ����ʵ�ִ���
	
	return S_OK;
}


STDMETHODIMP CQPServer::CreateSub(LONG subType, LONG tid)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.CreateSub(tid); // ��ѯ��������

	return S_OK;
}


STDMETHODIMP CQPServer::StepThrough(LONG nTableID)
{
	// TODO: �ڴ����ʵ�ִ���
	gloDataSvr.StepThrough(nTableID);
	return S_OK;
}
