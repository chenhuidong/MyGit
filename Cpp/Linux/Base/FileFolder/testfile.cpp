#include <fstream>  

int main(int argc, char** argv)
{
	std::ofstream ostr("/mnt/home2/51linux_LxomB0aQ/Log/1.log");
	ostr << "Hello, world!" << std::endl;
	ostr.close();
	return 0;
}
