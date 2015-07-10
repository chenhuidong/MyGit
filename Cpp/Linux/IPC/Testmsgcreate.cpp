#include "../../MyLinux.h"

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int c, oflag, mqid;

	oflag = SVMSG_MODE | IPC_CREAT;
	while((c = getopt(argc, argv,"e")) != -1)
	{
		switch(c)
		{
		case 'e':
			oflag != IPC_EXCL;
			break;
		}
	}

	if((optind != argc -1))
		LOG_ERROR<< "usage: msgcreate [-e] <pathname>"<< endl;

	mqid = msgget(ftok(argv[optind], 0), oflag);
	return 0;
}