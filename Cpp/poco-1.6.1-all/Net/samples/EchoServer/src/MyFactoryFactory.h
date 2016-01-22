#ifndef __MY_FACTORY_ADAPTER_H_
#define __MY_FACTORY_ADAPTER_H_
#include "MyDealFactory.h"
#include <string>

/*
class MyFactoryAdapter
{
public:
	MyFactoryAdapter();
	virtual ~MyFactoryAdapter(){}
	int Deal();

	void setClassName(const std::string &in_sClassName);
	const std::string& getClassName();
private:
	MyDealFactory m_oMyDealFactory;
	//MyDealFactory1 m_oMyDealFactory1;
	std::string m_sClassName;
};
*/

typedef Poco::DynamicFactory<Factory> FFactory;

class MyFactoryFactory
{
public:
	MyFactoryFactory();
	virtual ~MyFactoryFactory(){}
public:
	int CreateAllInstance(const std::string& in_sFactoryName);
private:
	MyDealFactory* m_pMyDealFactory;
private:
	FFactory m_oFFactory;
};

#endif 