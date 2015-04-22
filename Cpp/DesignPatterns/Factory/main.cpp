//main.cpp
#include "Factory.h" 
#include "Product.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	Factory* fac = new ConcreteFactory();
	Product* p1 = fac->CreateProduct1();
	Product* p2 = fac->CreateProduct2();
	Product* p3 = fac->CreateProduct3();
	return 0; 
}