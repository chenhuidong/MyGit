#define __MY_ERROR_
#include "../../../MyLinux.h"

int
main(int argc, char **argv)
{
	int		i, id;
	struct shmid_ds	buff;
	unsigned char	c, *ptr;

	if (argc != 2)
		err_quit("usage: shmread <pathname>");

	id = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
	ptr = (unsigned char *)shmat(id, NULL, 0);
	shmctl(id, IPC_STAT, &buff);

	printf("%s\n", ptr); 

	exit(0);
}
