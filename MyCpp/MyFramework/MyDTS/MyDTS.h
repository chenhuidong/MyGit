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
using namespace MMyLib;

typedef Poco::Tuple<int, std::string> task_param;
typedef std::vector<task_param> task_params;

typedef Poco::Tuple<int, std::string, int, std::string, int, std::string, std::string, std::string, std::string> task_paramtotal;
typedef std::vector<task_paramtotal> task_paramtotals;

#define BUFSIZE 256
#define DEBUG 1

class MyTable
{
public:
	std::string			m_sKeyPre;
	std::string			m_sSql;
	std::string			m_sTableName;
	std::vector<string> m_oColumns;		
};

class MyDTS
{
public:
	int InitializeAll();
	int UninitializeAll();
	int AnalyseConf(string in_sConfName);
	int ImportAllTables();
	//int AnalyseColumn(string in_sSql, std::vector<std::string> & out_oColunm);
	int AnalyseColumn(MyTable &in_oMyTable);

private:
	MMyLib::IMyDb 	 	m_oMyDb;
	MMyLib::IMyRedis 	m_oMyRedis;
	MMyLib::IMyConf  	m_oMyConf;
	//std::vector<string>	m_oSqls;
	std::vector<MyTable> m_oTables;
	task_params 		m_oTaskParams;
	task_paramtotals 	m_oTaskParamTotals;
};
#endif