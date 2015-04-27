//main.cpp
#include "Adapter1.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter(ade);
	adt->Request();
	return 0; 
}