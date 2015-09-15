//#include "MyEmail.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
	execl("./sendemail", "smtp.163.com", "chdyczx@163.com", "Chenhd@420462", "chdyczx@live.com", NULL);
	return 0;
}