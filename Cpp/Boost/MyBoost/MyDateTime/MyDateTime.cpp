#include "MyDateTime.h"

MMyLib::IMyDateTime::IMyDateTime()
{}

MMyLib::IMyDateTime::~IMyDateTime()
{}

ptime MMyLib::IMyDateTime::GetLocalTime()
{
	return second_clock::local_time();
}

ptime MMyLib::IMyDateTime::GetLocalTimeMic()
{
	return microsec_clock::local_time();
}

ptime MMyLib::IMyDateTime::GetUTCTime()
{
	return second_clock::universal_time();
}

ptime MMyLib::IMyDateTime::GetUTCTimeMic()
{
	return microsec_clock::universal_time();
}

string MMyLib::IMyDateTime::ToSimpleString(const ptime& in_oDateTime)
{
	return to_simple_string(in_oDateTime);
}

ptime MMyLib::IMyDateTime::AddDays(const ptime& in_oDateTime, int in_iDays)
{
	//date t_oDateTime = in_oDateTime.date();
	return in_oDateTime + hours(in_iDays * 24);
}

time_duration MMyLib::IMyDateTime::GetDuration(const ptime& in_oDateTimeLeft,  const ptime& in_oDateTimeRight)
{
	return in_oDateTimeLeft - in_oDateTimeRight;
}