#include "MyDealAdapter.h"

int MyDealAdapter::DealTransaction()
{
	MyDealFactory t_oMyDealFactory;

	t_oMyDealFactory.registerClass<MyDeal1>("MyDeal1");  
    t_oMyDealFactory.registerClass<MyDeal2>("MyDeal2");  

    assert (t_oMyDealFactory.isClass("MyDeal1"));  
    assert (t_oMyDealFactory.isClass("MyDeal2")); 

    MyDeal1* t_pMyDeal1 = dynamic_cast<MyDeal1*>(t_oMyDealFactory.createInstance("MyDeal1"));  
    //std::auto_ptr<MyDeal2> t_pMyDeal2(dynamic_cast<MyDeal2*>(t_oMyDealFactory.createInstance("MyDea2"))); 
    MyDeal2* t_pMyDeal2 = dynamic_cast<MyDeal2*>(t_oMyDealFactory.createInstance("MyDeal2"));  


    t_pMyDeal1->test();
    t_pMyDeal2->test();
	return 0;
}