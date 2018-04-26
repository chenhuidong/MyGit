#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
	char buf[] = "test";
	cout<< sizeof(buf)<< " "
		<< strlen(buf)<< " "
		<< sizeof(*buf)<< " "
		<< *buf<< " "
		<< buf<< " "
		<< buf[0]<< " "
		<< endl;

	char *buf1 = "test";
	cout<< sizeof(buf1)<< " "
		<< strlen(buf1)<< " "
		<< sizeof(*buf1)<< " "
		<< *buf1<< " "
		<< buf1<< " "
		<< buf[0]<< " "
		<< endl;

	const char *buf2 = "test";
	cout << buf2<< " "<< endl;
	buf2 = "my";
	cout << buf2<< " "<< endl;
	//*buf2 = 'm';
	//cout << buf2<< " "<< endl;

	char * const buf3 = "test";
	cout << buf3<< " "<< endl;
	//buf3 = "my";
	cout << *buf3<< " "<< endl;
	//*buf3 = 'm';
	//buf3[0] = 'm';
	cout << buf3[1]<< " "<< endl;

	return 0;
}