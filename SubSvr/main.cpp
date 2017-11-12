// #pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")
#include <iostream>
#include <objbase.h>
#include "GameData.h"
#include "BaseHog_h.h"
#include "CenterData_h.h"

#define			CHAIRSUM		20

HANDLE	hProcCtr = NULL;
HANDLE	hRCtr	= NULL;
IZySdn *pSdn = NULL;
IHog *pHog = NULL;

TableInfo tableInfo;
ChairInfo chairInfo[CHAIRSUM];

int GMStart( LONG ms); // 开始
int GMHog( LONG ms); // 开始

int main(int argc, char *argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED );

	/********************* 场景搭建 **********************/
	// 定义并初始化数据空间
	memset(&tableInfo, 0, sizeof tableInfo);
	memset(chairInfo, 0, sizeof (ChairInfo) * CHAIRSUM);

	// 提取控制句柄
	LPTSTR cmdLine = ::GetCommandLine();
	swscanf_s( cmdLine, L"mi_hProcCtr:%lld,mi_hRCtr:%lld,mi_tID:%ld", (LONGLONG *)&hProcCtr, (LONGLONG *)&hRCtr, &tableInfo.ti_tID);

	// 创建CenterData接口
	HRESULT hr = ::CoCreateInstance(__uuidof (ZySdn),
		NULL,
		CLSCTX_LOCAL_SERVER,
		__uuidof(IZySdn),
		(void **)&pSdn);

	// 创建Hog接口
	hr = ::CoCreateInstance(	__uuidof( Hog),
										NULL,
										CLSCTX_INPROC_SERVER,
										__uuidof(IHog),
										(void **)&pHog);
	pHog->BindHogData(&tableInfo, chairInfo, CHAIRSUM); // 叫庄接口绑定
	/************************* 场景搭建 ***************************/

	/************************** 游戏流程 **************************/
	GMStart(20000); // 游戏小局开始
	std::cout << "小局开始" <<  std::endl;
	int _hogId = GMHog( 15000); //玩家叫庄
	std::cout << "庄家为：nextID" << _hogId << std::endl;
	// 玩家下注
	// 发牌
	// 摊牌
	// 结算，等待玩家准备开始新的一局
	/**************************** 游戏流程 *************************/

	/********************** 游戏结束, 数据清理 **********************/
	pSdn->Release();
	pHog->Release();
	/********************** 游戏结束, 数据清理 **********************/

	::CoUninitialize();
	system("pause");
	return 0;
}

// 开始前椅子信息更新
int RefreshChair()
{
	// 玩家椅子号刷新
	for ( int i = 0; i< CHAIRSUM;++i)
	{
		LONG uid = 0;
		pSdn->GetChair(tableInfo.ti_tID, i, &uid);
		if ( uid == 0 && chairInfo[i].hs_uid == 0) // 空位置 不做任何事
		{
			chairInfo[i].hs_chair_enable = CHAIR_DISABLE;
		}
		else if (uid > 0 && chairInfo[i].hs_uid == 0) // 有人坐下
		{
			chairInfo[i].hs_uid = uid;
			chairInfo[i].hs_chair_enable = CHAIR_ENABLE;
		}
		else if (uid == 0 && chairInfo[i].hs_uid > 0) // 有人起立
		{
			memset(&chairInfo[i], 0, sizeof ChairInfo);
			chairInfo[i].hs_chair_enable = CHAIR_DISABLE;
		}
		else if (uid > 0 && chairInfo[i].hs_uid > 0 && uid != chairInfo[i].hs_uid) // 换人
		{
			memset(&chairInfo[i], 0, sizeof ChairInfo);
			chairInfo[i].hs_uid = uid;
			chairInfo[i].hs_chair_enable = CHAIR_ENABLE;
		}
	}
	
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
	RefreshChair(); // 刷新椅子信息
	pHog->InitHogData(HOG_NULL); // 叫庄状态复位

	::SetEvent(hRCtr);

	return 0;
}

// 叫庄
int GMHog( LONG ms)
{
	LONG nextID = -1;
	for( ;; )
	{
		// 开始
		::SetEvent(hRCtr);
		::WaitForSingleObject(hProcCtr, ms);
		::ResetEvent(hProcCtr);
		// 此处初始化数据空间
		LONG nChairId = -1;
		ENUM_HOG_STAT _hogSt;
		pSdn->GetHogMsg(tableInfo.ti_tID, &nChairId, &_hogSt);
		chairInfo[nChairId].hs_hot_state = _hogSt;
		
		// 计算庄
		BOOL hasNext = TRUE; 
		pHog->GenerateHog( &hasNext, &nextID);
		std::cout << "叫庄" << std::endl;
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