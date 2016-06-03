#ifndef __MY_LIB_MY_DATE_TIME_H_
#define __MY_LIB_MY_DATE_TIME_H_

#include "../MyStdAfx.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

namespace MMLIB
{
	class IMyDateTime
	{
	public:
		IMyDateTime();
		~IMyDateTime();
		ptime GetCurrentTime();
		string ToSimpleString(ptime& in_oDateTime);	
		ptime AddDays(ptime& in_oDateTime, int in_iDays);
		time_duration GetDuration(ptime& in_oDateTimeLeft, ptime& in_oDateTimeRight);
	private:
	};
}; 

#endif