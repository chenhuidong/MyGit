#ifndef __MY_FACTORY_ADAPTER_H_
#define __MY_FACTORY_ADAPTER_H_
#include "MyDealFactory.h"
#include <string>

typedef Poco::DynamicFactory<Factory> FFactory;

class MyFactoryFactory
{
public:
	MyFactoryFactory();
	virtual ~MyFactoryFactory(){}
public:
	int CreateAllFactory();
	int InitializeAllFactory();
	MyDealFactory* getMyDealFactory();
private:
	MyDealFactory* m_pMyDealFactory;
	FFactory m_oFFactory;
};

#endif 