#ifndef __MY_LIB_MY_DATE_TIME_H_
#define __MY_LIB_MY_DATE_TIME_H_

#include "../MyStdAfx.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

namespace MMyLib
{
	class IMyDateTime
	{
	public:
		IMyDateTime();
		~IMyDateTime();
		ptime GetLocalTime();
		ptime GetLocalTimeMic();
		ptime GetUTCTime();
		ptime GetUTCTimeMic();
		ptime AddDays(const ptime& in_oDateTime, double in_iDays);
		time_duration GetDuration(const ptime& in_oDateTimeLeft, const ptime& in_oDateTimeRight);
	private:
	};
}; 


#endif