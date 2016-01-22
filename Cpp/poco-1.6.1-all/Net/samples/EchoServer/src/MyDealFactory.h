#ifndef __MY_DEAL_FACTORY_H_
#define __MY_DEAL_FACTORY_H_
#include "Poco/DynamicFactory.h"
#include "MyDeal.h"
#include <string>

using Poco::DynamicFactory;

typedef Poco::DynamicFactory<MyDealBase> DFactory;

class MyDealFacotry
{
public:
	MyDealFacotry(){}
	virtual ~MyDealFacotry(){}
	int InitializeDFactory();
	int CreateInstance(std::string &in_sDealName);
private:
	DFactory m_oDFactory;
};

#endif 