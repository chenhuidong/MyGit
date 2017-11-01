#include "MyDb.h"
using namespace MMyLib;

int main(int argc, char** argv)
{
	std::string initFileName = "MyLog.properties";
	InitLog(initFileName.c_str());
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "testMyDb.db");
	t_oMyDb.Uninitialize();
	UninitLog();
	return 0;
}