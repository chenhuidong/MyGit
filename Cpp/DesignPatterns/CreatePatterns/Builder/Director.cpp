//Director.cpp
#include "Director.h" 
#include "Builder.h"

Director::Director(Builder* bld) 
{ 
	_bld = bld;
	cout<<"director begin..."<<endl;
}

Director::~Director() 
{
	cout<<"director end..."<<endl;
}

void Director::Construct() 
{ 
	_bld->BuildPartA("partA"); 
	_bld->BuildPartB("partB"); 
	_bld->BuildPartC("partC"); 
}