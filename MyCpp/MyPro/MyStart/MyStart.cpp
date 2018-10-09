#define FLAGS_INFO
#include "MyLog.h"
#include "MyStart.h"

int main(int argc, char** argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	//sqlite
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)0, "testMyDb.db");
	t_oMyDb.Uninitialize();
}