//Product.cpp
#include "Product.h" 

Product::Product() 
{ 
	cout<<"product begin.."<<endl; 
}

Product::~Product() 
{
	cout<<"product end.."<<endl; 
}

void Product::setPartA(const string& s)
{
	m_strA = s;
	cout<<"builded partA of product.."<<endl; 
}

void Product::setPartB(const string& s)
{
	m_strB = s;
	cout<<"builded partB of product..."<<endl; 
}

void Product::setPartC(const string& s)
{
	m_strC = s;
	cout<<"builded partC of product..."<<endl; 
}

const string& Product::getPartA()
{
	return m_strA;
}

const string& Product::getPartB()
{
	return m_strB;
}

const string& Product::getPartC()
{
	return m_strC;
}