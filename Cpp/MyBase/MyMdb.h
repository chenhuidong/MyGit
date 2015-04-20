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
	friend ostream &operator<<(ostream &oOutput,const CKeyClass &o)
	{	
		oOutput<<o.m_iKeyId;
		return oOutput;
	}

	//void setKeyId(int iKeyId)
	//{
	//	m_iKeyId = iKeyId;
	//}
	
	bool operator < (const CKeyClass& o) const
	{
		return m_iKeyId<o.m_iKeyId;
	}
	int m_iKeyId;
};

//#typedef map<CKeyClass, CPocket> CPocketMap;

template <class T>
class MyTable: public map<CKeyClass, T>
{
public:
	MyTable():m_iSequence(0){}

	void TInsert(CKeyClass &oKeyObj, T &oValueObj)
	{
		oValueObj._oid = m_iSequence++;
		insert( make_pair( oKeyObj, oValueObj));
	}

	int m_iSequence;
};


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

//int CPocketRecord::_oid = 0;


class CPocket: public MyTable<CPocketRecord>
{
//public:
};


#endif
