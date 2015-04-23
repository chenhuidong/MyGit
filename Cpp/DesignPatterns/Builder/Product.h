//Product.h
#ifndef _PRODUCT_H_ 
#define _PRODUCT_H_
#include "../../stdafx.h"

class Product 
{ 
public: 
	Product();
	~Product();
	void setPartA(const string& s);
	void setPartB(const string& s);
	void setPartC(const string& s);
protected:
private:
	string m_strA;
	string m_strB;
	string m_strC;
};

#endif //~_PRODUCT_H_