#include "Poco/ClassLibrary.h"
#include <iostream>

#if defined(_WIN32)
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API
#endif
extern "C" int LIBRARY_API hello();
int hello()
{
    std::cout << "Hello, world!" << std::endl;
}

class AbstractPlugin
{
public:
	AbstractPlugin();
	virtual ~AbstractPlugin();
	virtual void HelloWorld() = 0;
};

class PluginA: public AbstractPlugin
{
public:
	PluginA();
	virtual ~PluginA();

	void HelloWorld();
};

//g++ testSharedLibraryProvider.cpp -fPIC -shared -o libtestSharedLibrary.so