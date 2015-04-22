//Factory.cpp
#include "Factory.h"
#include "Product.h"
#include <iostream> 
using namespace std;

Factory::Factory() {}
Factory::~Factory() {}

ConcreteFactory::ConcreteFactory() 
{ 
	cout<<"ConcreteFactory....."<<endl; 
}

ConcreteFactory::~ConcreteFactory() {}

Product* ConcreteFactory::CreateProduct(const char* strConcreteProduct) 
{ 
	switch(strConcreteProduct)
	{
		case "ConcreteProduct1":return new ConcreteProduct1();
		case "ConcreteProduct2":return new ConcreteProduct2();
		case "ConcreteProduct3":return new ConcreteProduct3();
		default:return null;
	} 
}
