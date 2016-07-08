#include "MyNet.h"

int main(int argc, char** argv)
{
	try
	{
		MMyLib::INITIALIZE_LOG(argv[0]);
		cout<< "server start."<< endl;
		io_service ios;

		MMyLib::MyServer serv(ios);
		ios.run();
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
	}
	return 0;
}