//main.cpp
#include "Factory.h" 
#include "Product.h"
#include "../../stdafx.h"

int main(int argc,char* argv[]) 
{ 
	Factory* fac = new ConcreteFactory();
	Product* p1 = fac->CreateProduct("ConcreteProduct1");
	return 0; 
}