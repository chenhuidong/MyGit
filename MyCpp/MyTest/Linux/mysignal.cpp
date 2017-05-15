#include "signal.h"
#include "unistd.h"
#include <iostream>
using namespace std;

#define SIG_RECVDATA __SIGRTMIN+10

static void my_op(int)
{
	cout<< "my op"<< endl;
}

int main(int argc, char* argv[])
{
	signal(SIG_RECVDATA, my_op);
	sleep(20);
	return 0;
}