#include "../../stdafx.h"
#include "../../MySys.h"
#include "../../MyFile.h"
#include "../../MyIPC.h"


#define FLAGS_INFO
#include "../../MyLog.h"

int main(int argc, char **argv)
{
	INITIALIZE_LOG(argv[0]);

	struct Stat stat;
	if (argc != 2)
		LOG_ERROR << "usage: ftok <pathname>";

	Stat(argv[1], &Stat);
	LOG_INFO << "st_dev:" <<stat.st_dev <<", st_info:" <<stat.st_info <<", key:" <<Ftok(argv[1], 0x57) <<endl;
	return 0;
}