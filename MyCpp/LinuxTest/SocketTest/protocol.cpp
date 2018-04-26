#include <stdio.h>
#include <netdb.h>
#include <sys/utsname.h>

int main()
{
	struct protoent *ent;
	ent = getprotobyname("tcp");

	printf("%d\n", ent->p_proto);
	
	struct utsname name;
	uname(&name);
	printf("%s\n", name.machine);
	printf("%s\n", name.sysname);
	return 0;
}