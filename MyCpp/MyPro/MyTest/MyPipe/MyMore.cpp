#include "MyStdAfx.h"
#include <sys/wait.h>

#define	DEF_PAGER	"/bin/more"		/* default pager program */

int
main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	int		n;
	int		fd[2];
	pid_t	pid;
	char	*pager, *argv0;
	char	line[MYSIZE];
	FILE	*fp;

	if (argc != 2)
		LOG_ERROR<< "usage: a.out <pathname>"<< endl;

	if ((fp = fopen(argv[1], "r")) == NULL)
		LOG_ERROR<< "can't open "<< argv[1]<< endl;
	if (pipe(fd) < 0)
		LOG_ERROR<< "pipe error"<< endl;

	if ((pid = fork()) < 0) {
		LOG_ERROR<< "fork error"<< endl;
	} else if (pid > 0) {								/* parent */
		close(fd[0]);		/* close read end */

		/* parent copies argv[1] to pipe */
		while (fgets(line, MYSIZE, fp) != NULL) {
			n = strlen(line);
			if (write(fd[1], line, n) != n)
				LOG_ERROR<< "write error to pipe"<< endl;
		}
		if (ferror(fp))
			LOG_ERROR<< "fgets error"<< endl;

		close(fd[1]);	/* close write end of pipe for reader */

		if (waitpid(pid, NULL, 0) < 0)
			LOG_ERROR<< "waitpid error"<< endl;
		exit(0);
	} else {										/* child */
		close(fd[1]);	/* close write end */
		if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
				LOG_ERROR<< "dup2 error to stdin"<< endl;
			close(fd[0]);	/* don't need this after dup2 */
		}

		/* get arguments for execl() */
		if ((pager = getenv("PAGER")) == NULL)
			pager = DEF_PAGER;
		if ((argv0 = strrchr(pager, '/')) != NULL)
			argv0++;		/* step past rightmost slash */
		else
			argv0 = pager;	/* no slash in pager */

		if (execl(pager, argv0, (char *)0) < 0)
			LOG_ERROR<< "execl error for "<< pager<< endl;
	}
	exit(0);
}