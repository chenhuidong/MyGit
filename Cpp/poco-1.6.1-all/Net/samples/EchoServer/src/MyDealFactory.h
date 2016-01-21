#ifndef __MY_DEAL_FACTORY_H_
#define __MY_DEAL_FACTORY_H_
#include "Poco/DynamicFactory.h"
#include "MyDeal.h"

using Poco::DynamicFactory;

typedef Poco::DynamicFactory<MyDealBase> MyDealFactory; 

#endif 