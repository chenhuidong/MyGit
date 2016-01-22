#include "MyDeal.h"


MyDealBase::MyDealBase() {}
MyDealBase::~MyDealBase() {}
int MyDealBase::DealTransaction()
{
	/*
	if(std::strcmp(m_sDealName, "MyDeal1") == 0)
    {
        MyDeal1* t_pMyDeal1 = dynamic_cast<MyDeal1*>(m_oMyDealFactory.CreateInstance("MyDeal1"));
        t_pMyDeal1->test();
        delete t_pMyDeal1;
    }
    else if(std::strcmp(m_sDealName, "MyDeal2") == 0)
    {
        MyDeal2* t_pMyDeal2 = dynamic_cast<MyDeal2*>(m_oMyDealFactory.CreateInstance("MyDeal2"));
        t_pMyDeal2->test();
        delete t_pMyDeal2;
    }
    else
    {
        return -1;
    }
    */
	return 0;
}



MyDeal1::MyDeal1() 
{ 
	std::cout<<"MyDeal1...."<<std::endl; 
}

MyDeal1::~MyDeal1() 
{
	std::cout<<"MyDeal1....end"<<std::endl; 
}

void MyDeal1::test() 
{
	std::cout<<"test1"<<std::endl;
}


MyDeal2::MyDeal2() 
{ 
	std::cout<<"MyDeal2...."<<std::endl; 
}

MyDeal2::~MyDeal2() 
{
	std::cout<<"MyDeal2....end"<<std::endl; 
}

void MyDeal2::test() 
{
	std::cout<<"test2"<<std::endl;
}
