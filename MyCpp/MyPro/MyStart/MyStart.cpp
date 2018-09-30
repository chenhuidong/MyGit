#include "MyStart.h"

int main()
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	//sqlite
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)0, "testMyDb.db");
	t_oMyDb.Uninitialize();
}