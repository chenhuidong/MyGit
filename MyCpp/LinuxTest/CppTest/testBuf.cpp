#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	char buf[50];
	int r = 0;
	r = read(0, buf, sizeof(buf)-1);
	if(r<=0) return -1;
	buf[r] = 0;

	printf("buf:%s", buf);
	printf("size:%ld\n", sizeof(buf));
	printf("strlen:%ld\n", strlen(buf));

	char buf1[50] = {"test"};
	printf("strlen:%ld\n", strlen(buf1));

	return 0;
}