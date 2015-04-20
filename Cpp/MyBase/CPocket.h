#ifndef __CPOCKET_H
#define __CPOCKET_H
#include "MyMdb.h"

class CPocketRecord
{
public:
	CPocketRecord():acct_id(0), amount(0), deduct_value(0){}
	friend ostream &operator<<(ostream &oOutput,const CPocketRecord &o) 
	{
		oOutput<<o._oid<<" "<<o.acct_id<<" "<<o.amount<<" "<<o.deduct_value;
		return oOutput;
	}	

	void setPocketRecord(int iAcctId, int iAmount, int iDeductValue)
	{
		acct_id = iAcctId;
		amount = iAmount;
		deduct_value = iDeductValue;
	}

	int _oid;
	KEY(acct_id);
	FILED(int amount);
	FILED(int deduct_value);
};

class CPocket: public MyTable<CPocketRecord>
{
//public:
};

#endif