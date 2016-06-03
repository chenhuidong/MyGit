#include "MyDateTime.h"

MMLIB::MyDateTime::MyDateTime()
{}

MMLIB::MyDateTime::~MyDateTime()
{}

string& MMLIB::MyDateTime::ToSimpleString(string& io_sDstDateTime, ptime& in_oDateTime)
{
	return io_sDstDateTime = to_simple_string(in_oDateTime);
}

ptime& MMLIB::MyDateTime::GetCurrentTime(ptime& io_oDateTime)
{
	return io_oDateTime = second_clock::local_time();
}

ptime& MMLIB::MyDateTime::AddDays(ptime& io_oDstDateTime, ptime& in_oSrcDateTime, int in_iDays)
{
	date t_oSrcDateTime = in_oSrcDateTime.date();
	date t_oDstDateTime = t_oSrcDateTime + days(in_iDays);
	return io_oDstDateTime = t_oDstDateTime;
}

time_duration& MMLIB::MyDateTime::GetDuration(ptime& in_oDateTimeLeft, ptime& in_oDateTimeRight, time_duration& ot_oDuration)
{
	return ot_oDuration = in_oDateTimeLeft - in_oDateTimeRight;
}