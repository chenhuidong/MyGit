#include "../../stdafx.h"
#define FLAGS_INFO
#include "../../MyLog.h"

int main(int argc, char* argv[])
{
	INITIALIZE_LOG(argv[0]);

	int c;
	while((c=getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			LOG_ERROR << "output error." <<endl;

	if(ferror(stdin))
		LOG_ERROR << "input error" <<endl;
	return 0;
}