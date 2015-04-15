#ifndef __MY_BASE_H
#define __MY_BASE_H

#include "../stdafx.h"

class CKeyClass
{
public:
	CKeyClass():m_iKeyId(0){}
	CKeyClass(int iKeyId):m_iKeyId(iKeyId){}
	//CKeyClass(const CKeyClass & orig):m_iKeyId(orig.m_iKeyId){}
	/*
	CKeyClass& operator=(const CKeyClass &rhs)
	{
		m_iKeyId = rhs.m_iKeyId;
	}*/

	bool operator < (const CKeyClass& o) const
	{
		return true;
	}
	int m_iKeyId;
};

class CValueClass
{
public:
	CValueClass():m_iAmount(0), m_iDeductValue(0){}
	CValueClass(int iAmount, int iDeductValue):m_iAmount(iAmount), m_iDeductValue(iDeductValue){}
	//CValueClass(const CValueClass & orig):m_iAmount(orig.m_iAmount), m_iDeductValue(orig.m_iDeductValue){}
	/*CValueClass& operator=(const CValueClass &rhs)
	{
		m_iAmount = rhs.m_iAmount;
		m_iDeductValue = rhs.m_iDeductValue;
	}*/
	int m_iAmount;
	int m_iDeductValue;
};

class CRecord
{
public:
	CRecord(){}
	CRecord(int iKeyId, int iAmount, int iDeductValue):m_oKeyObj(iKeyId), m_oValueObj(iAmount, iDeductValue){}
	CKeyClass m_oKeyObj;
	CValueClass m_oValueObj;
};

//typedef map<CKeyClass, CValueClass> MyTable;

class MyTable: public map<CKeyClass, CValueClass>
{
public:
	void tinsert(int iKeyId, int iAmount, int iDeductValue);
};

void MyTable::tinsert(int iKeyId, int iAmount, int iDeductValue)
{
	CRecord t_oRecord(iKeyId, iAmount, iDeductValue);
	insert( make_pair( t_oRecord.m_oKeyObj, t_oRecord.m_oValueObj));
}

typedef map<CKeyClass, CValueClass>::iterator MyTableIter;

#endif