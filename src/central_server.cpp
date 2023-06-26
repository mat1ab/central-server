#include "central_server.h"
#include <iostream>

CentralServer::CentralServer() :
    port_(8080),
    authentication_module_(new AuthenticationModule()),
    resource_manager_(new ResourceManager()),
    task_queue_manager_(new TaskQueueManager()),
    resource_scheduler_(new ResourceScheduler()),
    rpc_communication_module_(new RpcCommunicationModule())
{
}

CentralServer::~CentralServer() {
}

void CentralServer::start() {

    // connect to an RPC server and retrieve GPU info
    std::string rpcAddress = "127.0.0.1"; // RPC server address
    int rpcPort = 9090; // RPC server port
    std::string gpuInfo = rpc_communication_module_->connectAndRetrieveGpuInfo(rpcAddress, rpcPort);
    std::cout << "RPC Server GPU Info: " << gpuInfo << std::endl;
}
