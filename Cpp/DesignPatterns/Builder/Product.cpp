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

void setPartA(const string& s)
{
	m_strA = s;
	cout<<"builded partA of product.."<<endl; 
}

void setPartB(const string& s)
{
	m_strB = s;
	cout<<"builded partB of product.."<<endl; 
}

void setPartC(const string& s)
{
	m_strC = s;
	cout<<"builded partC of product.."<<endl; 
}