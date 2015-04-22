//main.cpp
#include "Factory.h" 
#include "Product.h"
#include "../../stdafx.h"

int main(int argc,char* argv[]) 
{ 
	Factory* fac = new ConcreteFactory();
	Product* p1 = fac->CreateProduct("ConcreteProduct1");
	Product* p2 = fac->CreateProduct("ConcreteProduct2");
	Product* p3 = fac->CreateProduct("ConcreteProduct3");

	(ConcreteProduct1 *)p1->test();
	return 0; 
}