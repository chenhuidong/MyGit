#include "MyDateTime.h"

MMLIB::IMyDateTime::IMyDateTime()
{}

MMLIB::IMyDateTime::~IMyDateTime()
{}

ptime MMLIB::IMyDateTime::GetCurrentTime()
{
	return second_clock::local_time();
}

string MMLIB::IMyDateTime::ToSimpleString(ptime& in_oDateTime)
{
	return to_simple_string(in_oDateTime);
}

ptime MMLIB::IMyDateTime::AddDays(ptime& in_oDateTime, int in_iDays)
{
	date t_oDateTime = in_oDateTime.date();
	return ptime(t_oDateTime + days(in_iDays));
}

time_duration MMLIB::IMyDateTime::GetDuration(ptime& in_oDateTimeLeft, ptime& in_oDateTimeRight)
{
	return in_oDateTimeLeft - in_oDateTimeRight;
}