#include "MyMdb.h"

int  main(int argc, char const *argv[])
{
	CPocket mypocket(123, 234, 456);
	mypocket.TInsert(mypocket.acct_id, mypocket);
	//cout<<myrecord.m_acct_id.m_iKeyId<<" "<< myrecord.m_amount<<" "<<myrecord.m_deduct_value<<endl;
	cout<<mypocket[123].amount<<" "<<mypocket[123].deduct_value<<endl;
	return 0;
}