// Map a file into memory
#include "Poco/SharedMemory.h"
#include "Poco/File.h"
using Poco::SharedMemory;
using Poco::File;

int main(int argc, char** argv)
{
	File f("MapIntoMemory.dat");
	SharedMemory mem(f, SharedMemory::AM_READ); // read-only access
	for (char* ptr = mem.begin(); ptr != mem.end(); ++ptr)
	{
		// ...
	}
	return 0;
}
