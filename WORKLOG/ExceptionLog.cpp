/*****************************************************************
 **** 文件名：ExceptionLog.cpp
 ** 模块功能描述： 日志类实现文件
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
#include "ExceptionLog.h"
#include <time.h>


char ExceptionLog::m_strLPFilename[MAX_PATH] = { 0 };

ExceptionLog::ExceptionLog(void)
{
}

// 配置日志路径
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

// 写日志
int ExceptionLog::InputLog( const char *logdoc )
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs(m_strLPFilename, ios_base::app);
	if ( ofs.is_open() )
	{
		// 写入时间戳
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// 写入日志正文
		strcpy_s(logtxt, sizeof logtxt, logdoc);
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

// 写日志
int ExceptionLog::InputLogW( const wchar_t *logdoc )
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs(m_strLPFilename, ios_base::app);
	if ( ofs.is_open() )
	{
		// 写入时间戳
		char logtxt[MAX_PRELOG] = { 0 };
		standard_to_stamp(logtxt, MAX_PRELOG);
		ofs.write(logtxt, strlen(logtxt));

		// 写入日志正文
		WideCharToMultiByte(CP_ACP, NULL, logdoc, -1, logtxt, sizeof logtxt, NULL, NULL);
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

// 生成时间戳
int ExceptionLog::standard_to_stamp(char *const buffer, const size_t len)  
{  
	// 转换标准时间为时间戳
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
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