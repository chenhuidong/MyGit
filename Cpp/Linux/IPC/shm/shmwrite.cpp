#define __MY_ERROR_
#include "../../../MyLinux.h"

int
main(int argc, char **argv)
{
	int		i, id;
	struct shmid_ds	buff;
	unsigned char	*ptr;

	if (argc != 2)
		err_quit("usage: shmwrite <pathname>");

	id = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
	ptr = (unsigned char *)shmat(id, NULL, 0);
	shmctl(id, IPC_STAT, &buff);

	strcpy(ptr, "hello world.\n");

	exit(0);
}
