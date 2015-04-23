//main.cpp
#include "Singleton.h"

int main(int argc,char* argv[]) 
{ 
	Singleton* sgn = Singleton::Instance();
	return 0; 
}