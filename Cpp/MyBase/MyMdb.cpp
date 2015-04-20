#include "CPocket.h"

int  main(int argc, char const *argv[])
{
	CPocket tabPocket;
	CPocketRecord rPocketRecord;
	rPocketRecord.setPocketRecord(123, 234, 456);
	tabPocket.TInsert(rPocketRecord.acct_id, rPocketRecord);
	
	rPocketRecord.setPocketRecord(234, 456, 567);
    tabPocket.TInsert(rPocketRecord.acct_id, rPocketRecord);	

	//cout<<tabPocket[123].acct_id<<" "<<tabPocket[123].amount<<" "<<tabPocket[123].deduct_value<<endl;
	cout<<tabPocket[123]<<endl;
	cout<<tabPocket[234]<<endl;



	CPocket tabPocket1;
	CPocketRecord rPocketRecord1;
	rPocketRecord1.setPocketRecord(123, 234, 456);
	tabPocket1.TInsert(rPocketRecord1.acct_id, rPocketRecord1);
	
	rPocketRecord1.setPocketRecord(234, 456, 567);
    tabPocket1.TInsert(rPocketRecord1.acct_id, rPocketRecord1);	

	//cout<<tabPocket[123].acct_id<<" "<<tabPocket[123].amount<<" "<<tabPocket[123].deduct_value<<endl;
	cout<<tabPocket1[123]<<endl;
	cout<<tabPocket1[234]<<endl;
	return 0;
}
