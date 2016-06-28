#include "MyDb.h"

int main()
{
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize(MyDb::SQLite, "testMyDB");
	t_oMyDb.Uninitialize();
	return 0;
}