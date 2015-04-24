//main.cpp
#include "Abstraction.h" 
#include "AbstractionImp.h"
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	AbstractionImp* imp1 = new ConcreteAbstractionImpA();
	Abstraction* abs1 = new RefinedAbstraction(imp1);
	abs1->Operation(); 

	AbstractionImp* imp2 = new ConcreteAbstractionImpA();
	Abstraction* abs2 = new RefinedAbstraction(imp2);
	abs2->Operation(); 
	
	return 0; 
}