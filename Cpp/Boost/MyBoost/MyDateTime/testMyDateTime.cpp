#include "MyDateTime.h"
using namespace MMyLib;

int main()
{
	IMyDateTime t_oMyDateTime;

	cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTime())<< endl
	 << t_oMyDateTime.ToSimpleString(t_oMyDateTime.GetLocalTimeMic())<< endl;

	cout<< t_oMyDateTime.ToSimpleString(t_oMyDateTime.AddDays(t_oMyDateTime.GetLocalTime(), 1))<< endl;
	return 0;
}