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

Product* ConcreteFactory::CreateProduct1() 
{ 
	return new ConcreteProduct1(); 
}

Product* ConcreteFactory::CreateProduct2() 
{ 
	return new ConcreteProduct2(); 
}

Product* ConcreteFactory::CreateProduct3() 
{ 
	return new ConcreteProduct3(); 
}