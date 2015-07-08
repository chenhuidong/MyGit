#include "../../MyLinux.h"

int main(int argc, char **argv)
{
	size_t n;
	char buf[BUFFSIZE], command[BUFFSIZE];
	FILE *fp;

	fgets(buf, BUFFSIZE, stdin);

	n = strlen(buf);
	if(buf[n-1] == '\n')
		n--;

	snprintf(command, sizeof(command), "cat %s", buf);
	fp = popen(command, "r");

	while(fgets(buf, BUFFSIZE, fp) != NULL)
		fputs(buf, stdout);

	pclose(fp);
	return 0;
}