#include <iostream>
#include <map>
using namespace std;

void func(const map<int, int>& in_oMap)
{
	for(map<int, int>::iterator it = in_oMap.begin(); it!=in_oMap.end(); ++it)
	{
		cout<< it->first<< " "<< it->second<< endl;
	}
}

int main()
{
	map<int, int> t_oMap;
	t_oMap.insert(make_pair(1, 11));
	t_oMap.insert(make_pair(2, 22));

	for(map<int, int>::iterator it = t_oMap.begin(); it!=t_oMap.end(); ++it)
	{
		cout<< it->first<< " "<< it->second<< endl;
	}

	func(t_oMap);

	return 0;
}