//Composite.cpp
#include "Composite.h" 
#include "Component.h"
//#define NULL 0 //define NULL POINTOR

Composite::Composite() 
{ 
//vector<Component*>::iterator itend = comVec.begin(); 
}
Composite::~Composite() {}
void Composite::Operation() 
{ 
	vector<Component*>::iterator comIter = comVec.begin();
	for (;comIter != comVec.end();comIter++) 
	{ 
		(*comIter)->Operation(); 
	} 
}

void Composite::Add(Component* com) 
{ 
	comVec.push_back(com); 
}

void Composite::Remove(Component* com) 
{ 
	//comVec.erase(&com);
	//comVec.clear();
	vector<Component*>::iterator it;
	for(it=comVec.begin();it!=comVec.end();)
	{
		if(com==*it)
		{
			comVec.erase(it);
		}
		else
		{
			it++;
		}
	}

}

Component* Composite::GetChild(int index) 
{ 
	return comVec[index]; 
}