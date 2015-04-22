//main.cpp
#include "Factory.h" 
#include "Product.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	Factory* fac = new ConcreteFactory();
	Product* p = fac->CreateProduct1();
	Product* p = fac->CreateProduct2();
	Product* p = fac->CreateProduct3();
	return 0; 
}