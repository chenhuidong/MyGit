#include "../../../stdafx.h"
#include "../../../MyError.h"
#include "../../../MySys.h"

static void charatatime(const char *);

int
main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		charatatime("output from child 1111111111111111111111111111111111111111111\n");
	} else {
		charatatime("output from parent 222222222222222222222222222222222222222222\n");
	}
	exit(0);
}

static void
charatatime(const char *str)
{
	const char	*ptr;
	int		c;

	setbuf(stdout, NULL);			/* set unbuffered */
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}
