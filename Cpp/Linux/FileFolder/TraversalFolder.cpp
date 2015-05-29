#include <iostream>
#include 
#include "../../MyFile.h"

int main(int argc, char* argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2)
		std::cout<<"usage: ls folder"<<endl;
	if((dp = opendir(argv[1])) == NULL)
		std::cout<<"cannot open "<< argv[1] <<endl;
	while((dirp = readdir(dp)) != NULL)
		std::cout<<dirp->d_name<<endl;

	closedir(dp);
	return 0;
}
