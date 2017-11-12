#include <iostream>
#include <objbase.h>
#include "GameData.h"
#include "CenterData_h.h"
#include "CenterSvr_h.h"

int TCreatSUB()
{
	IZySdn *pzySdn = NULL;
	HRESULT hr = ::CoCreateInstance(__uuidof(ZySdn),
		NULL,
		CLSCTX_LOCAL_SERVER,
		__uuidof(IZySdn),
		(void **)&pzySdn);

	IQPServer *pQpsvr = NULL;
	hr = ::CoCreateInstance(__uuidof(QPServer),
		NULL,
		CLSCTX_LOCAL_SERVER,
		__uuidof(IQPServer),
		(void **)&pQpsvr);

	LONG nTableId = -1;
	pzySdn->CreateTable(&nTableId);	// 创建桌子
	pQpsvr->CreateSub(0, nTableId);	// 创建游戏进程

	// 游戏开始
	pzySdn->SetChair(nTableId, 0, 100);
	pzySdn->SetChair(nTableId, 1, 200);
	pzySdn->SetChair(nTableId, 5, 300);
	pzySdn->SetChair(nTableId, 3, 400);
	pzySdn->SetChair(nTableId, 4, 500);
	pQpsvr->StepThrough(nTableId);

	// 叫庄
	pzySdn->Hog(nTableId, 0, HOG_DOWN);
	pQpsvr->StepThrough(nTableId);
	pzySdn->Hog(nTableId, 1, HOG_DOWN);
	pQpsvr->StepThrough(nTableId);
	pzySdn->Hog(nTableId, 5, HOG_UP);
	pQpsvr->StepThrough(nTableId);
	pzySdn->Hog(nTableId, 3, HOG_DOWN);
	pQpsvr->StepThrough(nTableId);
	pzySdn->Hog(nTableId, 4, HOG_DOWN);
	pQpsvr->StepThrough(nTableId);

	// 下注

	pzySdn->Release();
	pQpsvr->Release();

	return 0;
}

int main(int argc, char argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	TCreatSUB();
	TCreatSUB();
	TCreatSUB();
	TCreatSUB(); 
	::CoUninitialize();
	return 0;
}