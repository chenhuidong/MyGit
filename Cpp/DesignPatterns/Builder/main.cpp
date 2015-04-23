//main.cpp
#include "Builder.h" 
#include "Product.h" 
#include "Director.h"

int main(int argc,char* argv[]) 
{
	ConcreteBuilder* pBuild = new ConcreteBuilder();
	Director* pDirector = new Director(pBuild);
	pDirector->Construct();
	Product * pProduct= pBuild->GetProduct();
	cout<<pProduct->getPartA()<<" "<<pProduct->getPartB()<<" "<<pProduct->getPartC()<<endl;
	return 0; 
}