/*****************************************************************
 **** �ļ�����ExceptionLog.cpp
 ** ģ�鹦�������� ��־��ʵ���ļ�
 **
 ** ��    �ߣ���Դ��
 ** ��    �䣺1421198728@qq.com
 ** �������ڣ�2017/11/22 16:19:57
 **
 ** �޸ı�ǣ�
 ** �޸�������
 **
 ** �޸ı�ǣ�
 ** �޸�������
 ******************************************************************/
#include "ExceptionLog.h"
#include <time.h>


char ExceptionLog::m_strLPFilename[MAX_PATH] = { 0 };

ExceptionLog::ExceptionLog(void)
{
}

// ������־·��
void ExceptionLog::ConfigLog(HMODULE hModule, const wchar_t *logFileName)
{
	wchar_t modulePath[MAX_PATH] = { 0 };
	GetModuleFileName(hModule, modulePath, MAX_PATH);
	wchar_t *tmp = modulePath + wcslen(modulePath);
	for (;;)
	{
		tmp--;
		if (L'\\' == *tmp ||
			L'/' == *tmp)
		{
			*tmp = NULL;
			break;
		}
	}
	wcscat_s(modulePath, MAX_PATH, L"\\");
	wcscat_s(modulePath, MAX_PATH, logFileName);

	memset(m_strLPFilename, 0, sizeof m_strLPFilename);
	WideCharToMultiByte(CP_ACP, NULL, modulePath, -1, m_strLPFilename, MAX_PATH, NULL, NULL);
}

// д��־
int ExceptionLog::InputLog( const char *logdoc )
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs(m_strLPFilename, ios_base::app);
	if ( ofs.is_open() )
	{
		// д��ʱ���
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// д����־����
		strcpy_s(logtxt, sizeof logtxt, logdoc);
		ofs.write(logtxt, strlen(logtxt)); // дʱ���
		ofs.clear();
		ofs.close();
	}
	else
	{
		// ����־ʧ��
		result = -1;
	}

	return result;
}

// д��־
int ExceptionLog::InputLogW( const wchar_t *logdoc )
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs(m_strLPFilename, ios_base::app);
	if ( ofs.is_open() )
	{
		// д��ʱ���
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// д����־����
		WideCharToMultiByte(CP_ACP, NULL, logdoc, -1, logtxt, sizeof logtxt, NULL, NULL);
		ofs.write(logtxt, strlen(logtxt)); // 
		ofs.clear();
		ofs.close();
	}
	else
	{
		// ����־ʧ��
		result = -1;
	}

	return result;
}

// ����ʱ���
int ExceptionLog::standard_to_stamp(char *const buffer, const size_t len)  
{  
	// ת����׼ʱ��Ϊʱ���
	time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
	tm t = { 0 };
	localtime_s(&t, &tt);
	sprintf_s(buffer, len, "\n\n%d-%02d-%02d %02d:%02d:%02d\n",
		t.tm_year + 1900,
		t.tm_mon + 1,
		t.tm_mday,
		t.tm_hour,
		t.tm_min,
		t.tm_sec);
	return 0;
} 