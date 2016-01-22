#include "MyFactoryAdapter.h"

MyFactoryAdapter::MyFactoryAdapter()
{
     m_oMyDealFactory.InitializeDFactory();
}

int MyFactoryAdapter::DealTransaction()
{	
    std::string s = "MyDeal1"; 
    m_oMyDealFactory.CreateInstance(s);
	return 0;
}