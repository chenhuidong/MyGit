#include "Element.h"
#include "Visitor.h" 
#include <iostream>
using namespace std; 

int main(int argc,char* argv[])
{
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();
	elm->Accept(vis);

	Visitor* vis1 = new ConcreteVisitorB();
	Element* elm1 = new ConcreteElementA();
	elm1->Accept(vis1);
	return 0;
}