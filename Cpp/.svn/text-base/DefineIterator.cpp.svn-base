#include <iostream>
#include <list>
#include <vector>
#include <sys/types.h>
using namespace std;

#define  ___ANONYMOUS1(var, line)  var##line
#define  __ANONYMOUS0(line)  ___ANONYMOUS1(_anonymous, line)
#define  ANONYMOUS()  __ANONYMOUS0(__LINE__)
#define ForEachOf(x, y, z) \
y::iterator ANONYMOUS() = z.end(); \
for(y::iterator x = z.begin();x != ANONYMOUS();++x)
#define ForEachOf_Const(x, y, z) \
	y::const_iterator ANONYMOUS() = z.end(); \
for(y::const_iterator x = z.begin();x != ANONYMOUS();++x)

#define ForEachOf_Reverse(x, y, z) \
	y::reverse_iterator ANONYMOUS() = z.rend(); \
for(y::reverse_iterator x = z.rbegin();x != ANONYMOUS();++x)

#define ForEachOf_Reverse_Const(x, y, z) \
	y::const_reverse_iterator ANONYMOUS() = z.rend(); \
for(y::const_reverse_iterator x = z.rbegin();x != ANONYMOUS();++x)

	typedef int8_t	int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef u_int8_t  uint8;
typedef u_int16_t uint16;
typedef u_int32_t uint32;
typedef u_int64_t uint64;

//typedef wchar_t wchar;

typedef list<int> IntList;
typedef vector<int> IntVec;


int main()
{
	IntList t_iList;
	t_iList.push_back(1);
	t_iList.push_back(2);
	t_iList.push_back(3);
	t_iList.push_back(4);
	t_iList.push_back(5);

	IntVec t_iVec;
	t_iVec.push_back(1);
	t_iVec.push_back(2);
	t_iVec.push_back(3);
	t_iVec.push_back(4);
	
	
	for(IntList::iterator it=t_iList.begin(); it!=t_iList.end(); ++it)
	{
		cout<<*it<<endl;
	}
	
	
	ForEachOf(it, IntList, t_iList)
	{
		cout<<*it<<endl;
	}
	
	ForEachOf_Reverse(it, IntVec, t_iVec)
	{
		cout<<*it<<endl;
	}
	
	
	return 0;
}
