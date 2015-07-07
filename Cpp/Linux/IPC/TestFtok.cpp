<<<<<<< HEAD
#include "../../MyIPC.h"

int main(int argc, char ** argv)
{
=======
#include "../../stdafx.h"
#include "../../MySys.h"
#include "../../MyFile.h"
#include "../../MyIPC.h"


#define FLAGS_INFO
#include "../../MyLog.h"

int main(int argc, char **argv)
{
	INITIALIZE_LOG(argv[0]);

	struct stat stat1;
	if (argc != 2)
		LOG_ERROR << "usage: ftok <pathname>";

	stat(argv[1], &stat1);
	cout << "st_dev:" <<stat1.st_dev <<", st_info:" <<stat1.st_ino <<", key:" <<ftok(argv[1], 0x57) <<endl;
>>>>>>> 66494e491f457d40f7940ba8c436132e5be1a1a8
	return 0;
}