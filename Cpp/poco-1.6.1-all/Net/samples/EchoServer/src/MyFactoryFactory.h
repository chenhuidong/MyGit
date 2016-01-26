#ifndef __MY_FACTORY_ADAPTER_H_
#define __MY_FACTORY_ADAPTER_H_
#include "MyDealFactory.h"
#include <string>
#include <map>

typedef Poco::DynamicFactory<Factory> FFactory;

class MyFactoryFactory
{
public:
	MyFactoryFactory();
	virtual ~MyFactoryFactory(){}
public:
	int CreateAllFactory();
	Factory* getFactory(const std::string& in_sFactoryName);
private:
	//MyDealFactory* m_pMyDealFactory;
	std::map<std::string, Factory*> m_mFFactory;
	FFactory m_oFFactory;
};

#endif 