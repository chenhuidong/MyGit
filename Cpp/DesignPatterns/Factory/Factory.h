//Factory.h
#ifndef _FACTORY_H_ 
#define _FACTORY_H_

class Product;
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

#endif //~_FACTORY_H_