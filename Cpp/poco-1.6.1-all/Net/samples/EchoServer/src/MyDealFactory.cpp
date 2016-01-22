#include "MyDealFactory.h"

int MyDealFactory::InitializeDFactory()
{
	m_oDFactory.registerClass<MyDeal1>("MyDeal1");  
    m_oDFactory.registerClass<MyDeal2>("MyDeal2");  

	return 0;
}

int MyDealFactory::CreateInstance(const std::string& in_sDealName)
{
	assert (m_oDFactory.isClass(in_sDealName));  
	m_oDFactory.createInstance(in_sDealName);

    //MyDeal1* t_pMyDeal1 = dynamic_cast<MyDeal1*>(m_oDFactory.createInstance("MyDeal1"));  
    //MyDeal2* t_pMyDeal2 = dynamic_cast<MyDeal2*>(m_oDFactory.createInstance("MyDeal2"));  

    //t_pMyDeal1->test();
    //t_pMyDeal2->test();
	return 0;
}