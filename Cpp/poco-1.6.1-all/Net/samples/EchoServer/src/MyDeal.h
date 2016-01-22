#ifndef __MY_DEAL_H_
#define __MY_DEAL_H_
#include <iostream> 

class MyDealBase
{ 
public: 
	virtual ~MyDealBase() = 0;
	virtual void test() = 0;
	int DealTransaction();
protected: 
	MyDealBase();
private:
};

class MyDeal1:public MyDealBase 
{ 
public: 
	~MyDeal1();
	MyDeal1(); 
	void test();
protected:
private:
};

class MyDeal2:public MyDealBase 
{ 
public: 
	~MyDeal2();
	MyDeal2(); 
	void test();
protected:
private:
};

#endif 