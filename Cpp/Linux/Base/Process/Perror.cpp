#include "../../../stdafx.h"
#include "../../../MyError.h"

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES：%s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}