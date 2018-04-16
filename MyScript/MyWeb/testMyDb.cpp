#include "MyDb.h"

int main(int argc, char** argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	MMyLib::MyDb t_oMyDb;
	t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=chenhuidong");
	t_oMyDb.Uninitialize();
	return 0;
}