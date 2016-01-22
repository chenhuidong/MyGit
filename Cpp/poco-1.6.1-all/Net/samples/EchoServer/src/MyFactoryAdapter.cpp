#include "MyFactoryAdapter.h"

MyFactoryAdapter::MyFactoryAdapter()
{
     m_oMyDealFactory.InitializeDFactory();
}

int MyFactoryAdapter::DealTransaction()
{	
	return 0;
}