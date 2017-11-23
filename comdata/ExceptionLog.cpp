#include "StdAfx.h"
#include "ExceptionLog.h"
#include <time.h>

ExceptionLog::ExceptionLog(void)
{
}

// 写日志
int ExceptionLog::InputLog( const char *logdoc )
{
	int result = 0;
	// 校验输入

	// 写日志
	ofstream ofs( "ReadXLS异常报告.txt", ios_base::app );
	if ( ofs.is_open() )
	{
		// 写入时间戳
		char logtxt[128] = { 0 };
		standard_to_stamp(logtxt, 128);
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

// 生成时间戳
int ExceptionLog::standard_to_stamp(char *const buffer, const size_t len)  
{  
	// 获取当前时间
    time_t t;
	time(&t);
	struct tm p = {0};
	gmtime_s(&p, &t);

	// 格式化打印
    strftime(buffer, len, "\n%Y-%m-%d %H:%M:%S\n", &p);
    return 0;
} 