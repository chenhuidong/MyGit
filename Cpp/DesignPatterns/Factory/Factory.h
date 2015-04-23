//Factory.h
#ifndef _FACTORY_H_ 
#define _FACTORY_H_
#include "../../stdafx.h"

class Product;
/*
class Factory 
{ 
public: 
	virtual ~Factory() = 0;
	virtual Product* CreateProduct(const char* strConcreteProduct) = 0;
protected: 
	Factory();
private:
};


class ConcreteFactory:public Factory 
{ 
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product* CreateProduct(const char* strConcreteProduct);
protected:
private:
};
*/
template <class T>
class Factory 
{ 
public: 
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
protected: 
	Factory();
private:
};

template <class T>
class AbstractFactory: public Factory
{
public:
	~AbstractFactory();
	AbstractFactory();
	template <class T>
	Product * CreateProduct();
};

#endif //~_FACTORY_H_