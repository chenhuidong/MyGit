#include "MyFactoryAdapter.h"

MyFactoryAdapter::MyFactoryAdapter()
{
     m_oMyDealFactory.InitializeDFactory();
}

int MyFactoryAdapter::DealTransaction()
{	
    m_oMyDealFactory.CreateInstance("MyDeal1");
	return 0;
}