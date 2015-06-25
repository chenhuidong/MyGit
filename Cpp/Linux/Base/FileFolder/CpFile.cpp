#include "../../../stdafx.h"


int main()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			cout<<"write_error"<<endl;
	
	if (n < 0)
	{
		cout<<"read error"<<endl;
	}
	return 0;
}