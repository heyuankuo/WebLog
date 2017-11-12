#pragma once
#include <fstream>
using std::ofstream;
using std::ios_base;
class DataProcLog
{
public:
	DataProcLog();
	~DataProcLog();

public:
	template <typename T>
	static void WriteSigleLog(char *formatStr, T _t);
};

template <typename T>
void DataProcLog::WriteSigleLog(char *formatStr, T _t)
{
	char destStr[64] = { 0 };
	sprintf_s(destStr, sizeof destStr, formatStr, _t);
	ofstream ofs("D:\\CenterData_log.txt", ios_base::app);
	ofs.write(destStr, strlen(destStr));
	ofs.clear();
	ofs.close();
}

