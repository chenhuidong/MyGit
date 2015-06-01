#include "../../../stdafx.h"
#include "../../../MyError.h"

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES：%sn", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}