#include "../../stdfile.h"

int main()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			std::out<<"write_error"<<std::endl;
	
	if (n < 0)
	{
		std::cout<<"read error"<<std::endl;
	}
	return 0;
}