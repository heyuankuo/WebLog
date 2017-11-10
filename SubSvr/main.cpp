#include <iostream>
#include <objbase.h>
#include "GameData.h"
#include "BaseHog_i.h"
#include "CenterData_i.h"

#define			CHAIRSUM		20

HANDLE	hProcCtr = NULL;
HANDLE	hRCtr	= NULL;

int GMStart( LONG ms); // ��ʼ
int GMHog( LONG ms, IHog *pHog); // ��ʼ

int main(int argc, char *argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED );

	/********************* ����� **********************/
	// �������ݿռ�
	TableInfo tableInfo;
	ChairInfo chairInfo[CHAIRSUM];

	// ��ȡ���ƾ��
	LPTSTR cmdLine = ::GetCommandLine();
	swscanf_s( cmdLine, L"mi_hProcCtr:%ld,mi_hRCtr:%ld,mi_tID:%ld", (LONG *)&hProcCtr, (LONG *)&hRCtr, &tableInfo.ti_tID);

	// ����Hog �ӿ�
	IHog *pHog = NULL;
	HRESULT hr = ::CoCreateInstance(	__uuidof( Hog),
										NULL,
										CLSCTX_INPROC_SERVER,
										__uuidof(IHog),
										(void **)&pHog);

	// ����CenterData�ӿ�
	IZySdn *pSdn = NULL;
	hr = ::CoCreateInstance(	__uuidof ( ZySdn),
								NULL,
								CLSCTX_LOCAL_SERVER,
								__uuidof( IZySdn ),
								(void ** )&pSdn );

	pHog->BindHogData(&tableInfo, chairInfo, CHAIRSUM); // ��
	pHog->InitHogData(HOG_NULL); // Hog��λ

	// GMStart( 15000); // ��ʼ
	// GMHog( 15000, pHog);

	pHog->Release();
	::CoUninitialize();
	return 0;
}

// ��ʼ
int GMStart( LONG ms)
{
	// ��ʼ
	::SetEvent(hRCtr);
	::WaitForSingleObject(hProcCtr, ms);
	::ResetEvent(hProcCtr);
	// �˴���ʼ�����ݿռ�

	::SetEvent(hRCtr);

	return 0;
}

// Hog
int GMHog( LONG ms, IHog *pHog)
{
	LONG nextID = -1;
	for( ;; )
	{
		// ��ʼ
		::SetEvent(hRCtr);
		::WaitForSingleObject(hProcCtr, ms);
		::ResetEvent(hProcCtr);
		// �˴���ʼ�����ݿռ�
		BOOL hasNext = TRUE; 
		pHog->GenerateHog( &hasNext, &nextID);
		::SetEvent(hRCtr);

		// �ж�
		if ( TRUE == hasNext) //����
		{
			continue;
		}
		else // ����
		{
			
			break;
		}
	}

	return nextID;
}