#include <boost/lexical_cast.hpp>
#include <vector>
#include <iostream>

void log_message(const std::string &s)
{
	std::cout<< s<< std::endl;
}

void log_errno(int yoko)
{
	log_message("Error " + boost::lexical_cast<std::string>(yoko) + ": " + strerror(yoko));
}

int main(int /*argc*/, char * argv[])
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
	std::vector<short> args;
	while (*++argv)
	{
		try
		{
			args.push_back(lexical_cast<short>(*argv));
		}
		catch(const bad_lexical_cast &)
		{
			args.push_back(0);
		}
	}

	for(std::vector<short>::iterator it=args.begin(); it!=args.end(); ++it)
	{
		std::cout<< *it<< std::endl;
	}

	log_errno(2);
// ...
}

