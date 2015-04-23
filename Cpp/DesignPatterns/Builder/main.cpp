//main.cpp
#include "Builder.h" 
#include "Product.h" 
#include "Director.h"

int main(int argc,char* argv[]) 
{
	ConcreteBuilder* pBuild = new ConcreteBuilder();
	Director* pDir = new Director(pBuild);
	pDir->Construct();
	return 0; 
}