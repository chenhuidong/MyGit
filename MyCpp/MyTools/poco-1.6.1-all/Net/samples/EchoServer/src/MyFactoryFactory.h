#ifndef __MY_FACTORY_ADAPTER_H_
#define __MY_FACTORY_ADAPTER_H_
#include "Poco/SingletonHolder.h"
#include "MyDealFactory.h"
#include <string>
#include <map>

typedef Poco::DynamicFactory<Factory> FFactory;

class MyFactoryFactory
{
public:
	MyFactoryFactory();
	virtual ~MyFactoryFactory();
public:
	Factory* getFactory(const std::string& in_sFactoryName);
	static MyFactoryFactory& DefaultFFactory();
private:
	//MyDealFactory* m_pMyDealFactory;
	std::map<std::string, Factory*> m_mFFactory;
	FFactory m_oFFactory;
private:
	int CreateAllFactory();
	MyFactoryFactory(const MyFactoryFactory&);
	MyFactoryFactory& operator = (const MyFactoryFactory&);
};

#endif 