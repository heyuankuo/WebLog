#include <iostream>
#include <objbase.h>
#include "GameData.h"
#include "BaseHog_i.h"
#include "CenterData_i.h"

#define			CHAIRSUM		20

HANDLE	hProcCtr = NULL;
HANDLE	hRCtr	= NULL;

int GMStart( LONG ms); // 开始
int GMHog( LONG ms, IHog *pHog); // 开始

int main(int argc, char *argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED );

	/********************* 场景搭建 **********************/
	// 定义数据空间
	TableInfo tableInfo;
	ChairInfo chairInfo[CHAIRSUM];

	// 提取控制句柄
	LPTSTR cmdLine = ::GetCommandLine();
	swscanf_s( cmdLine, L"mi_hProcCtr:%ld,mi_hRCtr:%ld,mi_tID:%ld", (LONG *)&hProcCtr, (LONG *)&hRCtr, &tableInfo.ti_tID);

	// 创建Hog 接口
	IHog *pHog = NULL;
	HRESULT hr = ::CoCreateInstance(	__uuidof( Hog),
										NULL,
										CLSCTX_INPROC_SERVER,
										__uuidof(IHog),
										(void **)&pHog);

	// 创建CenterData接口
	IZySdn *pSdn = NULL;
	hr = ::CoCreateInstance(	__uuidof ( ZySdn),
								NULL,
								CLSCTX_LOCAL_SERVER,
								__uuidof( IZySdn ),
								(void ** )&pSdn );

	pHog->BindHogData(&tableInfo, chairInfo, CHAIRSUM); // 绑定
	pHog->InitHogData(HOG_NULL); // Hog复位

	// GMStart( 15000); // 开始
	// GMHog( 15000, pHog);

	pHog->Release();
	::CoUninitialize();
	return 0;
}

// 开始
int GMStart( LONG ms)
{
	// 开始
	::SetEvent(hRCtr);
	::WaitForSingleObject(hProcCtr, ms);
	::ResetEvent(hProcCtr);
	// 此处初始化数据空间

	::SetEvent(hRCtr);

	return 0;
}

// Hog
int GMHog( LONG ms, IHog *pHog)
{
	LONG nextID = -1;
	for( ;; )
	{
		// 开始
		::SetEvent(hRCtr);
		::WaitForSingleObject(hProcCtr, ms);
		::ResetEvent(hProcCtr);
		// 此处初始化数据空间
		BOOL hasNext = TRUE; 
		pHog->GenerateHog( &hasNext, &nextID);
		::SetEvent(hRCtr);

		// 判断
		if ( TRUE == hasNext) //继续
		{
			continue;
		}
		else // 命中
		{
			
			break;
		}
	}

	return nextID;
}