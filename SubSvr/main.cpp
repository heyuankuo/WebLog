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

int GMStart( LONG ms); // ��ʼ
int GMHog( LONG ms); // ��ʼ

int main(int argc, char *argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED );

	/********************* ����� **********************/
	// ���岢��ʼ�����ݿռ�
	memset(&tableInfo, 0, sizeof tableInfo);
	memset(chairInfo, 0, sizeof (ChairInfo) * CHAIRSUM);

	// ��ȡ���ƾ��
	LPTSTR cmdLine = ::GetCommandLine();
	swscanf_s( cmdLine, L"mi_hProcCtr:%lld,mi_hRCtr:%lld,mi_tID:%ld", (LONGLONG *)&hProcCtr, (LONGLONG *)&hRCtr, &tableInfo.ti_tID);

	// ����CenterData�ӿ�
	HRESULT hr = ::CoCreateInstance(__uuidof (ZySdn),
		NULL,
		CLSCTX_LOCAL_SERVER,
		__uuidof(IZySdn),
		(void **)&pSdn);

	// ����Hog�ӿ�
	hr = ::CoCreateInstance(	__uuidof( Hog),
										NULL,
										CLSCTX_INPROC_SERVER,
										__uuidof(IHog),
										(void **)&pHog);
	pHog->BindHogData(&tableInfo, chairInfo, CHAIRSUM); // ��ׯ�ӿڰ�
	/************************* ����� ***************************/

	/************************** ��Ϸ���� **************************/
	GMStart(20000); // ��ϷС�ֿ�ʼ
	std::cout << "С�ֿ�ʼ" <<  std::endl;
	int _hogId = GMHog( 15000); //��ҽ�ׯ
	std::cout << "ׯ��Ϊ��nextID" << _hogId << std::endl;
	// �����ע
	// ����
	// ̯��
	// ���㣬�ȴ����׼����ʼ�µ�һ��
	/**************************** ��Ϸ���� *************************/

	/********************** ��Ϸ����, �������� **********************/
	pSdn->Release();
	pHog->Release();
	/********************** ��Ϸ����, �������� **********************/

	::CoUninitialize();
	system("pause");
	return 0;
}

// ��ʼǰ������Ϣ����
int RefreshChair()
{
	// ������Ӻ�ˢ��
	for ( int i = 0; i< CHAIRSUM;++i)
	{
		LONG uid = 0;
		pSdn->GetChair(tableInfo.ti_tID, i, &uid);
		if ( uid == 0 && chairInfo[i].hs_uid == 0) // ��λ�� �����κ���
		{
			chairInfo[i].hs_chair_enable = CHAIR_DISABLE;
		}
		else if (uid > 0 && chairInfo[i].hs_uid == 0) // ��������
		{
			chairInfo[i].hs_uid = uid;
			chairInfo[i].hs_chair_enable = CHAIR_ENABLE;
		}
		else if (uid == 0 && chairInfo[i].hs_uid > 0) // ��������
		{
			memset(&chairInfo[i], 0, sizeof ChairInfo);
			chairInfo[i].hs_chair_enable = CHAIR_DISABLE;
		}
		else if (uid > 0 && chairInfo[i].hs_uid > 0 && uid != chairInfo[i].hs_uid) // ����
		{
			memset(&chairInfo[i], 0, sizeof ChairInfo);
			chairInfo[i].hs_uid = uid;
			chairInfo[i].hs_chair_enable = CHAIR_ENABLE;
		}
	}
	
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
	RefreshChair(); // ˢ��������Ϣ
	pHog->InitHogData(HOG_NULL); // ��ׯ״̬��λ

	::SetEvent(hRCtr);

	return 0;
}

// ��ׯ
int GMHog( LONG ms)
{
	LONG nextID = -1;
	for( ;; )
	{
		// ��ʼ
		::SetEvent(hRCtr);
		::WaitForSingleObject(hProcCtr, ms);
		::ResetEvent(hProcCtr);
		// �˴���ʼ�����ݿռ�
		LONG nChairId = -1;
		ENUM_HOG_STAT _hogSt;
		pSdn->GetHogMsg(tableInfo.ti_tID, &nChairId, &_hogSt);
		chairInfo[nChairId].hs_hot_state = _hogSt;
		
		// ����ׯ
		BOOL hasNext = TRUE; 
		pHog->GenerateHog( &hasNext, &nextID);
		std::cout << "��ׯ" << std::endl;
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