#define __MY_THREAD_
#include "../../../MyLinux.h"

#define	SEM_NAME	"mysem"

int		count = 0;

int
main(int argc, char **argv)
{
	int		i, nloop;
	sem_t	*mutex;

	if (argc != 2)
		err_quit("usage: incr1 <#loops>");
	nloop = atoi(argv[1]);

		/* 4create, initialize, and unlink semaphore */
	mutex = sem_open(px_ipc_name(SEM_NAME), O_CREAT | O_EXCL, FILE_MODE, 1);
	sem_unlink(px_ipc_name(SEM_NAME));

	setbuf(stdout, NULL);	/* stdout is unbuffered */
	if (fork() == 0) {		/* child */
		for (i = 0; i < nloop; i++) {
			sem_wait(mutex);
			printf("child: %d\n", count++);
			sem_post(mutex);
		}
		exit(0);
	}

		/* 4parent */
	for (i = 0; i < nloop; i++) {
		sem_wait(mutex);
		printf("parent: %d\n", count++);
		sem_post(mutex);
	}
	exit(0);
}