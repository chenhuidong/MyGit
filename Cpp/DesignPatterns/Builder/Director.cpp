//Director.cpp
#include "Director.h" 
#include "Builder.h"

Director::Director(Builder* bld) 
{ 
	_bld = bld;
}

Director::~Director() 
{
	delete _bld;
	_bld = NULL;
	cout<<"director delete"<<endl;
}

void Director::Construct() 
{ 
	_bld->BuildPartA("partA"); 
	_bld->BuildPartB("partB"); 
	_bld->BuildPartC("partC"); 
}