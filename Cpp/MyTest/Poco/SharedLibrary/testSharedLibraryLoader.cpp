// LibraryLoaderTest.cpp
#include "Poco/SharedLibrary.h"
#include <iostream>

using Poco::SharedLibrary;
typedef void (*HelloFunc)(); // function pointer type
int main(int argc, char** argv)
{
        std::string path("/mnt/home2/51linux_LxomB0aQ/MyProgram/MyGit/Cpp/Poco/SharedLibrary/libtestSharedLibrary");
        path.append(SharedLibrary::suffix()); // adds ".dll" or ".so"
        SharedLibrary library(path); // will also load the library
        HelloFunc func = (HelloFunc) library.getSymbol("hello");
        func();
        library.unload();
        return 0;
}

//g++ testSharedLibraryLoader.cpp -omain -lPocoFoundation
