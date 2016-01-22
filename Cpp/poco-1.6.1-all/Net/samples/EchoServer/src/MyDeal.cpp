#include "MyDeal.h"


MyDealBase::MyDealBase() {}
MyDealBase::~MyDealBase() {}


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
