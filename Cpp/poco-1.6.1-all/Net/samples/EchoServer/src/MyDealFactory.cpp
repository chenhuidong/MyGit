#include "MyDealFactory.h"

int MyDealFacotry::InitializeDFactory()
{
	m_oDFactory.registerClass<MyDeal1>("MyDeal1");  
    m_oDFactory.registerClass<MyDeal2>("MyDeal2");  

    assert (m_oDFactory.isClass("MyDeal1"));  
    assert (m_oDFactory.isClass("MyDeal2")); 

    MyDeal1* t_pMyDeal1 = dynamic_cast<MyDeal1*>(m_oDFactory.createInstance("MyDeal1"));  
    MyDeal2* t_pMyDeal2 = dynamic_cast<MyDeal2*>(m_oDFactory.createInstance("MyDeal2"));  

    t_pMyDeal1->test();
    t_pMyDeal2->test();
	return 0;
}

int CreateInstance(std::string &in_sDealName)
{
	return 0;
}