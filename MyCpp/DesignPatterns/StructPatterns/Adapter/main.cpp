//main.cpp
#include "Adapter.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	//Adapter* adt = new Adapter();
	Target* adt = new Adapter();
	adt->Request();
	return 0; 
}