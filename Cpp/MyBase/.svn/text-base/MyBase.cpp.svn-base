#include "MyBase.h"

int main(int argc, char const *argv[])
{
	MyTable mytable;

	mytable.tinsert(123, 100, 50);
	mytable.tinsert(234, 20, 10);
	/*mytable.insert( make_pair( CKeyClass(234), CValueClass(20, 10)));
	mytable.insert( make_pair( CKeyClass(345), CValueClass(30, 20)));
	mytable.insert( make_pair( CKeyClass(456), CValueClass(60, 50)));
	mytable.insert( make_pair( CKeyClass(567), CValueClass(100, 50)));
*/

	//cout<<mytable.size()<<endl;
	//CValueClass t_oValueClass = mytable[CKeyClass(567)];
	//cout<<t_oValueClass.m_iAmount<<" "<<t_oValueClass.m_iDeductValue<<endl;

	for(MyTableIter it=mytable.begin(); it!=mytable.end(); ++it)
	{
		cout<<it->first.m_iKeyId<<" "<<it->second.m_iAmount<<" "<<it->second.m_iDeductValue<<endl;
	}
	return 0;
}
