#ifndef __MY_FACTORY_ADAPTER_H_
#define __MY_FACTORY_ADAPTER_H_
#include "MyDealFactory.h"
#include <string>

class MyFactoryAdapter
{
public:
	MyFactoryAdapter();
	virtual ~MyFactoryAdapter(){}
	int DealTransaction();
private:
	MyDealFactory m_oMyDealFactory;
};

#endif 