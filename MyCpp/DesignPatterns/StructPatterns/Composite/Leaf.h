//Leaf.h
#ifndef _LEAF_H_ 
#define _LEAF_H_
#include "Component.h"

class Leaf:public Component 
{ 
public: 
	Leaf();
	~Leaf();
	void Operation();
protected:
private:
}; 

class Leaf1:public Component 
{ 
public: 
	Leaf1();
	~Leaf1();
	void Operation();
protected:
private:
}; 

#endif //~_LEAF_H_