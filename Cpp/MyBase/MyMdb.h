#ifndef __MY_MDB_H
#define __MY_MDB_H

#include "../stdafx.h"

class CKeyClass;
#define KEY(key) CKeyClass key
#define FILED(filed) filed

class CKeyClass
{
public:
	CKeyClass():m_iKeyId(0){}
	CKeyClass(int iKeyId):m_iKeyId(iKeyId){}
	bool operator < (const CKeyClass& o) const
	{
		return true;
	}
	int m_iKeyId;
};

class CPocket;
//#typedef map<CKeyClass, CPocket> CPocketMap;

template <class T>
class MyTable: public map<CKeyClass, T>
{
public:
	void TInsert(CKeyClass &oKeyObj, T &oValueObj)
	{
		insert( make_pair( oKeyObj, oValueObj));
	}

};

class CPocket: public MyTable<CPocket>
{
public:
	CPocket():acct_id(0), amount(0), deduct_value(0){}
	CPocket(int iAcctId, int iAmount, int iDeductValue):acct_id(iAcctId), amount(iAmount), deduct_value(iDeductValue){}

	KEY(acct_id);
	FILED(int amount);
	FILED(int deduct_value);
};


#endif