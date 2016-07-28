/* Simple program that uses the gregorian calendar to progress by exactly
* one month, irregardless of how many days are in that month.
*
* This method can be used as an alternative to iterators
*/
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
int
main()
{
	using namespace boost::gregorian;
	date d = day_clock::local_day();
	add_month mf(1);
	date d2 = d + mf.get_offset(d);
	std::cout << "Today is: " << to_simple_string(d) << ".\n"
	<< "One month from today will be: " << to_simple_string(d2)
	<< std::endl;
	return 0;
}