//Visitor.cpp
#include "Visitor.h"
#include "Element.h" 
#include <iostream>
using namespace std; 

Visitor::Visitor() {} 
Visitor::~Visitor() {} 

ConcreteVisitorA::ConcreteVisitorA() {} 
ConcreteVisitorA::~ConcreteVisitorA() {}

void ConcreteVisitorA::VisitConcreteElementA(Element* elm)
{
	cout<<"i will visit ConcreteElementAA..."<<endl;
} 

void ConcreteVisitorA::VisitConcreteElementB(Element* elm)
{
	cout<<"i will visit ConcreteElementAB..."<<endl;
} 


ConcreteVisitorB::ConcreteVisitorB() {} 
ConcreteVisitorB::~ConcreteVisitorB() {} 

void ConcreteVisitorB::VisitConcreteElementA(Element* elm)
{
	cout<<"i will visit ConcreteElementBA..."<<endl;
} 

void ConcreteVisitorB::VisitConcreteElementB(Element* elm)
{
	cout<<"i will visit ConcreteElementBB..."<<endl;
}