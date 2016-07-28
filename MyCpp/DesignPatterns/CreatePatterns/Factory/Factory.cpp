//Factory.cpp
#include "Factory.h"
#include "Product.h"


Factory::Factory() {}
Factory::~Factory() {}

ConcreteFactory::ConcreteFactory() 
{ 
	cout<<"ConcreteFactory....."<<endl; 
}

ConcreteFactory::~ConcreteFactory() {}

Product* ConcreteFactory::CreateProduct(const char* strConcreteProduct) 
{ 
	if(strcmp(strConcreteProduct, "ConcreteProduct1") == 0)
		return new ConcreteProduct1();
	else if (strcmp(strConcreteProduct, "ConcreteProduct2") == 0)
		return new ConcreteProduct2();
	else if (strcmp(strConcreteProduct, "ConcreteProduct3") == 0)
		return new ConcreteProduct3();
	else 
		return NULL;
}
