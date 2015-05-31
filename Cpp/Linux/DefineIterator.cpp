#include "../stdafx.h"


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
