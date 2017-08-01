#include "MyDb.h"

int main(int argc, char** argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)2, "testMyDb.db");
	t_oMyDb.Uninitialize();
	return 0;
}