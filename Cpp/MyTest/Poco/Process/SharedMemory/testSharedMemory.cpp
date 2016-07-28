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

/*
// Share a memory region of 1024 bytes
#include "Poco/SharedMemory.h"
using Poco::SharedMemory;
int main(int argc, char** argv)
{
	SharedMemory mem("MySharedMemory", 1024,
		SharedMemory::AM_READ | SharedMemory::AM_WRITE);
	for (char* ptr = mem.begin(); ptr != mem.end(); ++ptr)
	{
		*ptr = 0;
	}
	return 0;
}
*/