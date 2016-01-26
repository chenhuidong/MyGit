#ifndef __MY_DEAL_FACTORY_H_
#define __MY_DEAL_FACTORY_H_
#include "Poco/DynamicFactory.h"
#include "MyDeal.h"
#include <string>
#include <assert.h>

using Poco::DynamicFactory;

typedef Poco::DynamicFactory<MyDealBase> DFactory;

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual int Initialize() = 0;
protected:
	Factory(){}
private:
};

class MyDealFactory: public Factory
{
public:
	MyDealFactory(){}
	virtual ~MyDealFactory();
	int Initialize();
public:
	MyDealBase* CreateInstance(const std::string& in_sDealName);
private:
	std::map<std::string, MyDealBase*> m_mMyDealBase;
	DFactory m_oDFactory;
};

#endif 