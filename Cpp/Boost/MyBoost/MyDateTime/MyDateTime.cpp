#include "MyDateTime.h"

MMyLib::IMyDateTime::IMyDateTime()
{}

MMyLib::IMyDateTime::~IMyDateTime()
{}

ptime MMyLib::IMyDateTime::GetCurrentTime()
{
	//return second_clock::local_time();
	return second_clock::universal_time();
}

string MMyLib::IMyDateTime::ToSimpleString(const ptime& in_oDateTime)
{
	return to_simple_string(in_oDateTime, 'yyyymmdd');
}

ptime MMyLib::IMyDateTime::AddDays(const ptime& in_oDateTime, int in_iDays)
{
	date t_oDateTime = in_oDateTime.date();
	return ptime(t_oDateTime + days(in_iDays));
}

time_duration MMyLib::IMyDateTime::GetDuration(const ptime& in_oDateTimeLeft,  const ptime& in_oDateTimeRight)
{
	return in_oDateTimeLeft - in_oDateTimeRight;
}