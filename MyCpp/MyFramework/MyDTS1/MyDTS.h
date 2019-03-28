#ifndef __MY_DTS_H_
#define __MY_DTS_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "MyDb.h"
#include "MySharedLibrary.h"
#include "MyRedis.h"
#include "MyBaseFunc.h"
#include "MyConf.h"
#include <iostream>
#include "MyTable.h"
#include "CTUSERS1.h"
#include "CTUSERS2.h"
using namespace MMyLib;

#define BUFSIZE 256
#define DEBUG 1

class MyDTS
{
public:
	int InitializeAll();
	int UninitializeAll();
	int AnalyseConf(string in_sConfName);
	int AnalyseColumn(MyTable &in_oMyTable);
	int ImportAllTables();

	template <typename T>
	int ImportTable(MyTable &in_oMyTable, T& t);

private:
	MMyLib::IMyDb 	 	m_oMyDb;
	MMyLib::IMyRedis 	m_oMyRedis;
	MMyLib::IMyConf  	m_oMyConf;
	std::vector<MyTable> m_oTables;
};
#endif