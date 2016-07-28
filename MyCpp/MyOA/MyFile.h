#ifndef __MY_FILE_H_
#define __MY_FILE_H_
#include <fstream>  

class MyFile
{
public:
	MyFile(){}
	~MyFile(){}
	int OpenFile();
	int WriteFile();
	int CloseFile();
public:
	std::ofstream ostr;
};

#endif