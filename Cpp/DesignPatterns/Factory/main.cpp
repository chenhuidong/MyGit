//main.cpp
#include "Factory.h" 
#include "Product.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	Factory* fac = new ConcreteFactory();
	Product* p1 = fac->CreateProduct("ConcreteProduct1");
	return 0; 
}