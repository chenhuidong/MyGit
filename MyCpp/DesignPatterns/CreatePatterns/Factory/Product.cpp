//Product.cpp
#include "Product.h"
#include <iostream> 
using namespace std;

Product::Product() {}
Product::~Product() {}

ConcreteProduct1::ConcreteProduct1() 
{ 
	cout<<"ConcreteProduct1...."<<endl; 
}

ConcreteProduct1::~ConcreteProduct1() {}
void ConcreteProduct1::test() 
{
	cout<<"test1"<<endl;
}


ConcreteProduct2::ConcreteProduct2() 
{ 
	cout<<"ConcreteProduct2...."<<endl; 
}

ConcreteProduct2::~ConcreteProduct2() {}

ConcreteProduct3::ConcreteProduct3() 
{ 
	cout<<"ConcreteProduct3...."<<endl; 
}

ConcreteProduct3::~ConcreteProduct3() {}
