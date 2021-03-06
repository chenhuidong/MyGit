/*
#include "../../stdafx.h"
#include "../../MySys.h"
#include "../../MyFile.h"
#include "../../MyIPC.h"


#define FLAGS_INFO
#include "../../MyLog.h"
*/
#include "../../MyLinux.h"

int main(int argc, char **argv)
{
	INITIALIZE_LOG(argv[0]);

	struct stat stat1;
	if (argc != 2)
		LOG_ERROR<< "usage: ftok <pathname>";

	stat(argv[1], &stat1);
	cout<< "st_dev:"<< hex<< stat1.st_dev<< ", st_ino:"<< hex<< stat1.st_ino<< ", key:"<< hex<< ftok(argv[1], 0x57)<< endl;
	return 0;
}