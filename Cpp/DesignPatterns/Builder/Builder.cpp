//Builder.cpp
#include "Builder.h" 
#include "Product.h"
#include <iostream>
using namespace std;

Builder::Builder() {}
Builder::~Builder() {}

ConcreteBuilder::ConcreteBuilder()
{
	cout<<"concrete bulider..."<<buildPara<<endl; 
	m_pProduct = new Product();
}

ConcreteBuilder::~ConcreteBuilder() 
{
	delete m_pProduct;
	m_pProduct = NULL;
}

void ConcreteBuilder::BuildPartA(const string& buildPara) 
{ 
	cout<<"Step1:Build PartA..."<<buildPara<<endl; 
	m_pProduct->setPartA(buildPara);
}

void ConcreteBuilder::BuildPartB(const string& buildPara) 
{
	cout<<"Step1:Build PartB..."<<buildPara<<endl; 
	m_pProduct->setPartB(buildPara);
}

void ConcreteBuilder::BuildPartC(const string& buildPara) 
{ 
	cout<<"Step1:Build PartC..."<<buildPara<<endl; 
	m_pProduct->setPartC(buildPara);
}

Product* ConcreteBuilder::GetProduct() 
{ 
	return m_pProduct; 
}