#include "MySignal.h"

static void	sig_usr(int);	/* one handler for both signals */

int main(int argc, char** argv)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2");
	for ( ; ; )
		pause();
	return 0;
}

static void
sig_usr(int signo)		/* argument is signal number */
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n", signo);
}
