#include "MyDateTime.h"
using namespace MMyLib;

int main()
{
	IMyDateTime t_oMyDateTime;
	//cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetCurrentTime())<< endl;
	//ptime t_oPtime = t_oMyDateTime.GetCurrentTime();
	cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTime())<< endl
	 << t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTimeMic())<< endl;

	//cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.AddDays(t_oMyDateTime.GetCurrentTime(), 1))<< endl;
	return 0;
}