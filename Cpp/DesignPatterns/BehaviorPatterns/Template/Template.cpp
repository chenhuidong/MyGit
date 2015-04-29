#include "Template.h" 
#include <iostream>
using namespace std; 

AbstractClass::AbstractClass() {} 
AbstractClass::~AbstractClass() {} 
void AbstractClass::TemplateMethod() 
{
	this->PrimitiveOperation1();
	this->PrimitiveOperation2();
} 

ConcreteClass1::ConcreteClass1() {} 
ConcreteClass1::~ConcreteClass1() {} 
void ConcreteClass1::PrimitiveOperation1()
{
	cout<<"ConcreteClass1...PrimitiveOperat
	ion1"<<endl;
} 

void ConcreteClass1::PrimitiveOperation2()
{
	cout<<"ConcreteClass1...PrimitiveOperat
	ion2"<<endl;
} 

ConcreteClass2::ConcreteClass2() {} 
ConcreteClass2::~ConcreteClass2() {} 
void ConcreteClass2::PrimitiveOperation1()
{
	cout<<"ConcreteClass2...PrimitiveOperat
	ion1"<<endl;
} 

void ConcreteClass2::PrimitiveOperation2()
{
	cout<<"ConcreteClass2...PrimitiveOperat
	ion2"<<endl;
}

