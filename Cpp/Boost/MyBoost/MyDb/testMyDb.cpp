#include "MyDb.h"

int main(int argc, char** argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize(3, "testMyDb.db");
	t_oMyDb.Uninitialize();
	return 0;
}