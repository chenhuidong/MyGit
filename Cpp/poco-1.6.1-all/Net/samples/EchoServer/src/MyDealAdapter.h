#ifndef __MY_DEAL_ADAPTER_H_
#define __MY_DEAL_ADAPTER_H_
#include "MyDealFactory.h"

class MyDealAdapter
{
public:
	MyDealAdapter(){}
	virtual ~MyDealAdapter(){}
	int DealTransaction();
};

#endif 