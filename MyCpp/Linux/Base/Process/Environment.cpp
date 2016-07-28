/*
#include <stdio.h>
int main(void)
{ 
	extern char **environ; 
	int i; 
	for(i=0; environ[i]!=NULL; i++) 
		printf("%s\n", environ[i]); 
	return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
int main(void)
{ 
	printf("PATH=%s\n", getenv("PATH")); 
	//setenv("PATH", "hello", 1); 
	//printf("PATH=%s\n", getenv("PATH")); 
	return 0;
}