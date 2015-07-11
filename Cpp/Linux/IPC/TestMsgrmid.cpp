#include "../../MyLinux.h"

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int mqid;

	if(argc != 2)
		cout<< "usage: msgrmid <pathname>"<< endl;

	mqid = msgget(ftok(argv[1], 0), 0);
	msgctl(mqid, IPC_RMID, NULL);
	return 0;
}