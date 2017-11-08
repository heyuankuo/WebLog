#include <iostream>
#include <objbase.h>
#include "BaseHog_i.h"

int main(int argc, char *argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED );
	// 创建座子信息
	TableInfo tableInfo = {0};
	ChairInfo chairInfo[8];

	// Hog接口
	IHog *pHog = NULL;
	HRESULT hr = ::CoCreateInstance(	__uuidof( Hog),
										NULL,
										CLSCTX_INPROC_SERVER,
										__uuidof(IHog),
										(void **)&pHog);

	pHog->BindHogData(&tableInfo, chairInfo, 8, (LONG)hProCtr); // 绑定

	// 开始
	pHog->InitHogData(HOG_NULL);
	for(;;)
	{
		//pHog->WaitForHog();
	}
	
	::CoUninitialize();
	return 0;
}