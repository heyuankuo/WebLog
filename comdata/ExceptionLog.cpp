#include "StdAfx.h"
#include "ExceptionLog.h"
#include <time.h>

ExceptionLog::ExceptionLog(void)
{
}

// д��־
int ExceptionLog::InputLog( const char *logdoc )
{
	int result = 0;
	// У������

	// д��־
	ofstream ofs( "ReadXLS�쳣����.txt", ios_base::app );
	if ( ofs.is_open() )
	{
		// д��ʱ���
		char logtxt[128] = { 0 };
		standard_to_stamp(logtxt, 128);
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

// ����ʱ���
int ExceptionLog::standard_to_stamp(char *const buffer, const size_t len)  
{  
	// ��ȡ��ǰʱ��
    time_t t;
	time(&t);
	struct tm p = {0};
	gmtime_s(&p, &t);

	// ��ʽ����ӡ
    strftime(buffer, len, "\n%Y-%m-%d %H:%M:%S\n", &p);
    return 0;
} 