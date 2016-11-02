#include "MyStdAfx.h"
using namespace MMyLib;

#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "ProcessMng.grpc.pb.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using processmng::ProcessMngRequest;
using processmng::ProcessMngReply;
using processmng::ProcessMng;

enum PSTATUS
{
  STARTING = 0,
  STARTUP = 1,
  STARTFAILED = 2,
  STOPING = 3,
  STOPED = 4,
  STOPFAILED = 5,
};

struct ProcessStat
{
public:
  int m_iConditionId;
  int m_iPid;
  PSTATUS m_iPStat;
};

typedef map<int,ProcessStat> ProcessMap;

// Logic and data behind the server's behavior.
class ProcessMngServiceImpl final : public ProcessMng::Service 
{
  Status BeginTask(ServerContext* context, const ProcessMngRequest* request,
    ProcessMngReply* reply) override 
  {   
    string t_sBinPath = getBinPath();
    t_sBinPath += "/MyFrame";
    LOG_INFO<< "Exec file path is "<< t_sBinPath<< " ."<< endl;

    int t_iConditionId = request->conditionid();

    int t_pid = fork(); 
    if(t_pid < 0)
    {
      LOG_ERROR<< "Fork error."<< endl;
      reply->set_returncode("-1"); 
      return Status::OK;
    }
    else if(0 == t_pid)
    {
      ProcessStat t_oProcessStat;
      t_oProcessStat.m_iConditionId = t_iConditionId;
      t_oProcessStat.m_iPid = t_pid;
      t_oProcessStat.m_iPStat = PSTATUS::STARTING;
      m_mapProcess.insert(make_pair(t_oProcessStat.m_iConditionId, t_oProcessStat));
           
      char *arg[]={"MyFrame",(char *)MMyLib::itoa(t_iConditionId).c_str(),NULL};
      execv(t_sBinPath.c_str(), arg);
      exit(-1);
    }
    else
    {
      LOG_INFO<< "Wait my son task."<< endl;
      int t_iStatus = 0;

      waitpid(t_pid, &t_iStatus, 0);
      if(WIFEXITED(t_iStatus))
      {
        m_mapProcess[t_iConditionId].m_iPStat = PSTATUS::STOPED;
        LOG_INFO<< "Exec success, Return code is "<< WEXITSTATUS(t_iStatus)<< " ."<< endl;
        reply->set_returncode(MMyLib::itoa(WEXITSTATUS(t_iStatus)));
        return Status::OK;
      }
      else 
      {
        m_mapProcess[t_iConditionId].m_iPStat = PSTATUS::STOPED;
        LOG_ERROR<< "Child process exit abnormally "<< WEXITSTATUS(t_iStatus)<< endl;
        reply->set_returncode(MMyLib::itoa(WEXITSTATUS(t_iStatus))); 
        return Status::OK;
      }
    }
    return Status::OK;
  }

  Status EndTask(ServerContext* context, const ProcessMngRequest* request,
    ProcessMngReply* reply) override 
  {
    int t_iConditionId = request->conditionid();
    int t_iPid = m_mapProcess[t_iConditionId].m_iPid;
    int t_iStatus = 0;

    if(kill(t_iPid, SIGINT))
    {
      waitpid(t_iPid, &t_iStatus, 0);
      LOG_ERROR<< "kill "<< t_iConditionId<< " failed."<< endl;
      reply->set_returncode("-1");
    }
    LOG_INFO<< "Kill success."<< endl;
    reply->set_returncode("0");
    return Status::OK;
  }

  Status GetTaskStatus(ServerContext* context, const ProcessMngRequest* request,
    ProcessMngReply* reply) override 
  {
    return Status::OK;
  }

private:
  ProcessMap m_mapProcess;
};

void RunServer() 
{
  std::string server_address("127.0.0.1:54321");
  ProcessMngServiceImpl service;

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) 
{
  MMyLib::INITIALIZE_LOG(argv[0]);
  RunServer();

  return 0;
}