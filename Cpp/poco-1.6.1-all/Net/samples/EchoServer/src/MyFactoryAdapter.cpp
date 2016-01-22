#include "MyFactoryAdapter.h"

MyFactoryAdapter::MyFactoryAdapter()
{
     m_oMyDealFactory.InitializeDFactory();
}

int MyFactoryAdapter::DealTransaction()
{	
    MyDeal1* t_pMyDeal1 = dynamic_cast<MyDeal1*>(m_oMyDealFactory.CreateInstance("MyDeal1"));
    t_pMyDeal1->test();
    delete t_pMyDeal1;
	return 0;
}