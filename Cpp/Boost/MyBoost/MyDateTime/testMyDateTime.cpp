#include "MyDateTime.h"
using namespace MMyLib;

int main()
{
	IMyDateTime t_oMyDateTime;

	cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTime())<< endl
	 << t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTimeMic())<< endl;

	cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.AddDays(t_oMyDateTime.GetLocalTime(), 0.5))<< endl;
	cout<< t_oMyDateTime.ToSimpleString(ptime(t_oMyDateTime.AddDays(t_oMyDateTime.GetLocalTime(), 0.5) - t_oMyDateTime.GetLocalTime()))<< endl;
	return 0;
}