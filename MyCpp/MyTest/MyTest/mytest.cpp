#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <list>
#include <iostream>
#include <string.h>
using namespace std;

#define  MIN(x,y) (x)<(y)?(x):(y)
int main()
{
	int i = 10,j = 13,k;
	k=10*MIN(i,j);
	printf("%d\n",k);
	
    return 0;
}