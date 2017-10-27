#include "MyDateTime.h"
using namespace MMyLib;

int main()
{
	IMyDateTime t_oMyDateTime;

	cout<< to_simple_string(t_oMyDateTime.GetLocalTime())<< endl
	 << to_simple_string(t_oMyDateTime.GetLocalTimeMic())<< endl;

	cout<< to_simple_string(t_oMyDateTime.AddDays(t_oMyDateTime.GetLocalTime(), 1))<< endl;
	cout<< to_simple_string(t_oMyDateTime.AddDays(t_oMyDateTime.GetLocalTime(), 1) - t_oMyDateTime.GetLocalTime())<< endl;
	return 0;
}