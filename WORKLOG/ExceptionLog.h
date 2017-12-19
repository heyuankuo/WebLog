/*****************************************************************
 **** 文件名：ExceptionLog.h
 ** 模块功能描述： 日志类声明文件
 **
 ** 作    者：何源阔
 ** 邮    箱：1421198728@qq.com
 ** 创建日期：2017/11/22 16:19:57
 **
 ** 修改标记：
 ** 修改描述：
 **
 ** 修改标记：
 ** 修改描述：
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
	 * 配置日志名称和地址
	 * @param		hModule			[in]		模块地址
	 * @param		logFileName		[in]		日志文件名称
	 */
	static void ConfigLog(HMODULE hModule, const wchar_t *logFileName);

public:
	// 写日志
	static int InputLog( const char *logdoc ); 
	static int InputLogW( const wchar_t *logdoc ); 

	template <typename T>
	static int InputLog(const char *logFormat, T _t);

	template <typename T>
	static int InputLogW(const wchar_t *logFormat, T _t);

	template <typename T, typename K, typename V>
	static int InputLogW(const wchar_t *logFormat, T _t, K _k, V _v);

protected:
	// 获取当前时间
	static int standard_to_stamp(char *const buffer, const size_t len); 

protected:
	static char m_strLPFilename[MAX_PATH];
};

template <typename T>
static int ExceptionLog::InputLog(const char *logFormat, T _t)
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// 写入时间戳
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// 写入日志正文
		sprintf_s(logtxt, sizeof logtxt, logFormat, _t);
		ofs.write(logtxt, strlen(logtxt)); // 写时间戳
		ofs.clear();
		ofs.close();
	}
	else
	{
		// 打开日志失败
		result = -1;
	}

	return result;
}

template <typename T>
static int ExceptionLog::InputLogW(const wchar_t *logFormat, T _t)
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// 写入时间戳
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// 写入日志正文
		wchar_t Wlogtxt[MAX_PRELOG] = { 0 };
		swprintf_s(Wlogtxt, sizeof logtxt / sizeof (wchar_t) , logFormat, _t);

		WideCharToMultiByte(CP_ACP, NULL, Wlogtxt, -1, logtxt, sizeof logtxt, NULL, NULL);
		ofs.write(logtxt, strlen(logtxt)); // 
		ofs.clear();
		ofs.close();
	}
	else
	{
		// 打开日志失败
		result = -1;
	}

	return result;
}


template <typename T, typename K, typename V>
static int ExceptionLog::InputLogW(const wchar_t *logFormat, T _t, K _k, V _v )
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs(m_strLPFilename, ios_base::app);
	if (ofs.is_open())
	{
		// 写入时间戳
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// 写入日志正文
		wchar_t Wlogtxt[MAX_PRELOG] = { 0 };
		swprintf_s(Wlogtxt, sizeof logtxt / sizeof(wchar_t), logFormat, _t, _k, _v );

		WideCharToMultiByte(CP_ACP, NULL, Wlogtxt, -1, logtxt, sizeof logtxt, NULL, NULL);
		ofs.write(logtxt, strlen(logtxt)); // 
		ofs.clear();
		ofs.close();
	}
	else
	{
		// 打开日志失败
		result = -1;
	}

	return result;
}