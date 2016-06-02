#ifndef __MY_LIB_MY_DATE_TIME_H_
#define __MY_LIB_MY_DATE_TIME_H_

#include "../MyStdAfx.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

namespace MMLIB
{
	class MyDateTime
	{
	public:
		MyDateTime();
		~MyDateTime();
		string& ToSimpleString(string& io_sDstDateTime, ptime& in_oDateTime);
		ptime& GetCurrentTime(ptime& io_oDateTime);
		ptime& AddDays(ptime& io_oDstDateTime, ptime& in_oSrcDateTime, int in_iDays);
		time_duration& GetDuration(ptime& in_oDateTimeLeft, ptime& in_oDateTimeRight, time_duration& ot_oDuration);
	private:
	};
}; 

#endif