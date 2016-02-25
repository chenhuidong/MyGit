#include <boost/lexical_cast.hpp>
#include <boost/array.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>

void log_message(const std::string &s)
{
	std::cout<< s<< std::endl;
}

void log_errno(int yoko)
{
	log_message("Error " + boost::lexical_cast<std::string>(yoko) + ": " + strerror(yoko));
}

void number_to_file(int number, FILE* file)
{
	typedef boost::array<char, 50> buf_t; // You can use std::array if your compiler supports it
	buf_t buffer = boost::lexical_cast<buf_t>(number); // No dynamic memory allocation
	fputs(buffer.begin(), file);
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
	number_to_file(20, "1.txt");
}

