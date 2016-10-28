#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "ProcessMng.grpc.pb.h"
#include "MyStdAfx.h"

using namespace MMyLib;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using processmng::ProcessMngRequest;
using processmng::ProcessMngReply;
using processmng::ProcessMng;

// Logic and data behind the server's behavior.
class ProcessMngServiceImpl final : public ProcessMng::Service 
{
  Status BeginTask(ServerContext* context, const ProcessMngRequest* request,
                  ProcessMngReply* reply) override 
  {
    //std::string prefix("Hello ");
    //reply->set_message(prefix + request->name());
    int status = 0;
    string t_sBinPath = getBinPath();
    t_sBinPath += "/MyFrame";
    LOG_INFO<< "Exec file path is "<< t_sBinPath<< endl;

    int t_pid = fork(); 
    if(t_pid < 0)
    {
      LOG_ERROR<< "Fork error."<< endl;
      return Status::CANCELLED;
    }
    else if(0 == t_pid)
    {
      int t_iConditionId = request->conditionid();
      LOG_INFO<< "Condition id is "<< t_iConditionId<< endl;

      char *arg[]={"MyFrame",(char *)MMyLib::itoa(t_iConditionId).c_str(),NULL};
      execv(t_sBinPath.c_str(), arg);
      LOG_INFO<< "Exec success."<< endl;
    }
    else
    {
      LOG_INFO<< "Wait my son task."<< endl;
      wait(&status);
      if(WIFEXITED(status))
      {
        printf("the return code is %d./n", WEXITSTATUS(status));
        reply->set_returncode(0); 
      }
    }
    return Status::OK;
  }

  Status EndTask(ServerContext* context, const ProcessMngRequest* request,
                  ProcessMngReply* reply) override 
  {
    return Status::OK;
  }

  Status GetTaskStatus(ServerContext* context, const ProcessMngRequest* request,
                  ProcessMngReply* reply) override 
  {
    return Status::OK;
  }
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