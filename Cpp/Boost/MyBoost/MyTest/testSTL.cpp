#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> t_oMap;
	t_oMap.insert(1, 11);
	t_oMap.insert(2, 22);

	for(map<int, int>::iterator it = t_oMap.begin(); it!=t_oMap.end(); ++it)
	{
		cout<< it->first<< " "<< it->second<< endl;
	}
	return 0;
}