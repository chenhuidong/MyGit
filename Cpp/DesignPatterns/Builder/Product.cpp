//Product.cpp
#include "Product.h" 

Product::Product() 
{ 
	cout<<"bulid a product.."<<endl; 
}

Product::~Product() 
{
	cout<<"bulided a product.."<<endl; 
}

void Product::setPartA(const string& s)
{
	m_strA = s;
	cout<<"builded partA of product.."<<endl; 
}

void Product::setPartB(const string& s)
{
	m_strB = s;
	cout<<"builded partB of product.."<<endl; 
}

void Product::setPartC(const string& s)
{
	m_strC = s;
	cout<<"builded partC of product.."<<endl; 
}

const string& getPartA()
{
	return m_strA;
}

const string& getPartB()
{
	return m_strB;
}

const string& getPartC()
{
	return m_strC;
}