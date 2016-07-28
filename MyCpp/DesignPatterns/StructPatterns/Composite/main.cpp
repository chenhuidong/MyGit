//main.cpp
#include "Component.h" 
#include "Composite.h" 
#include "Leaf.h" 
#include <iostream> 
using namespace std;

int main(int argc,char* argv[]) 
{ 
	Leaf* l = new Leaf(); 
	l->Operation();
	cout<<"1"<<endl<<endl;

	Composite* com = new Composite();
	com->Add(l);
	com->Operation();
	cout<<"2"<<endl<<endl;
	
	Component* ll = com->GetChild(0);
	/*
	ll->Operation();
	cout<<"3"<<endl<<endl;
	*/
	Leaf1* lll = new Leaf1(); 
	lll->Operation();
	cout<<"4"<<endl<<endl;

	com->Add(lll);
	com->Operation();
	cout<<"5"<<endl<<endl;

	com->Remove(ll);
	com->Operation();
	cout<<"6"<<endl<<endl;

	return 0; 
}