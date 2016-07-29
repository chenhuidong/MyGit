// TestLibrary.cpp
#include <iostream>
#if defined(_WIN32)
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API
#endif
extern "C" void LIBRARY_API hello();
void hello()
{
       std::cout << "Hello, world!" << std::endl;
}

class PluginA
{
public:
	void HelloWorld()
	{
       std::cout << "hello, world!" << std::endl;
	}
};

POCO_EXPORT_CLASS(PluginA)
//g++ testSharedLibraryProvider.cpp -fPIC -shared -o libtestSharedLibrary.so