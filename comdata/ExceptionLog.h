#pragma once
#include <fstream>
#include <time.h>
using std::ofstream;
using std::ios_base;
ref class ExceptionLog
{
public:
	ExceptionLog(void);

public:
	// 写日志
	static int InputLog( const char *logdoc ); 

	template <typename T>
	static int InputLog(const char *logFormat, T _t);

protected:
	static int standard_to_stamp(char *const buffer, const size_t len); 

protected:
};

template <typename T>
static int ExceptionLog::InputLog(const char *logFormat, T _t)
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs("ReadXLS异常报告.txt", ios_base::app);
	if (ofs.is_open())
	{
		// 写入时间戳
		char logtxt[128] = { 0 };
		standard_to_stamp(logtxt, 128);
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