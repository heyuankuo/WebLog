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
	// д��־
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
	// У������

	// д��־
	ofstream ofs("ReadXLS�쳣����.txt", ios_base::app);
	if (ofs.is_open())
	{
		// д��ʱ���
		char logtxt[128] = { 0 };
		standard_to_stamp(logtxt, 128);
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