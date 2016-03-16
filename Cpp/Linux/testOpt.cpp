#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
	int c;
	while (-1 != (c = getopt(argc, argv,
          "a:"  /* Max item size */
          "p"   /* Sasl ON */
		)))
	{
		switch (c) 
		{
			case 'a':
				cout<< "chd a" <<optarg <<endl; break;
			case 'p':
				cout<< "chd p" <<endl; break;
			default:
				break;
		}
	}
	return 0;
}
