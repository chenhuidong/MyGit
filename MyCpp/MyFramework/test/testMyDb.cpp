#include "MyDb.h"
using namespace MMyLib;

int main(int argc, char** argv)
{
	std::string initFileName = "MyLog.properties";
	InitLog(initFileName.c_str());
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)0, "testMyDb.db");
	*t_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Employees (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
	t_oMyDb.Uninitialize();
	UninitLog();
	return 0;
}