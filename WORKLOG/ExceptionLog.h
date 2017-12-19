/*****************************************************************
 **** �ļ�����ExceptionLog.h
 ** ģ�鹦�������� ��־�������ļ�
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
#pragma once
#include <objbase.h>
#include <fstream>
#include <time.h>
using std::ofstream;
using std::ios_base;
#define		MAX_PRELOG			512

class ExceptionLog
{
public:
	ExceptionLog(void);

public:
	/**
	 * ������־���ƺ͵�ַ
	 * @param		hModule			[in]		ģ���ַ
	 * @param		logFileName		[in]		��־�ļ�����
	 */
	static void ConfigLog(HMODULE hModule, const wchar_t *logFileName);

public:
	// д��־
	static int InputLog( const char *logdoc ); 
	static int InputLogW( const wchar_t *logdoc ); 

	template <typename T>
	static int InputLog(const char *logFormat, T _t);

	template <typename T>
	static int InputLogW(const wchar_t *logFormat, T _t);

	template <typename T, typename K, typename V>
	static int InputLogW(const wchar_t *logFormat, T _t, K _k, V _v);

protected:
	// ��ȡ��ǰʱ��
	static int standard_to_stamp(char *const buffer, const size_t len); 

protected:
	static char m_strLPFilename[MAX_PATH];
};

template <typename T>
static int ExceptionLog::InputLog(const char *logFormat, T _t)
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// д��ʱ���
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// д����־����
		sprintf_s(logtxt, sizeof logtxt, logFormat, _t);
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

template <typename T>
static int ExceptionLog::InputLogW(const wchar_t *logFormat, T _t)
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// д��ʱ���
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// д����־����
		wchar_t Wlogtxt[MAX_PRELOG] = { 0 };
		swprintf_s(Wlogtxt, sizeof logtxt / sizeof (wchar_t) , logFormat, _t);

		WideCharToMultiByte(CP_ACP, NULL, Wlogtxt, -1, logtxt, sizeof logtxt, NULL, NULL);
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


template <typename T, typename K, typename V>
static int ExceptionLog::InputLogW(const wchar_t *logFormat, T _t, K _k, V _v )
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// д��ʱ���
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// д����־����
		wchar_t Wlogtxt[MAX_PRELOG] = { 0 };
		swprintf_s(Wlogtxt, sizeof logtxt / sizeof(wchar_t), logFormat, _t, _k, _v );

		WideCharToMultiByte(CP_ACP, NULL, Wlogtxt, -1, logtxt, sizeof logtxt, NULL, NULL);
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