#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char**argv)
{
	int c;
	while (-1 != (c = getopt(argc, argv,
          "a:"  
          "p"
		)))
	{
		switch (c) 
		{
			case 'a':
				cout<< "chd a " <<atoi(optarg) <<endl; break;
			case 'p':
				cout<< "chd p" <<endl; break;
			default:
				break;
		}
	}
	return 0;
}
