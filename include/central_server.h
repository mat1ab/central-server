#ifndef CENTRAL_SERVER_H
#define CENTRAL_SERVER_H

#include <string>
#include <vector>
#include <memory>
#include "authentication.h"
#include "resource_manager.h"
#include "task_queue_manager.h"
#include "resource_scheduler.h"
#include "rpc_communication_module.h"

class CentralServer
{
public:
    CentralServer();
    ~CentralServer();
    void start();
    void shutdown();

private:
    std::atomic<bool> running;
    int port_;
    std::unique_ptr<AuthenticationModule> authentication_module_;
    std::unique_ptr<ResourceManager> resource_manager_;
    std::unique_ptr<TaskQueueManager> task_queue_manager_;
    std::unique_ptr<ResourceScheduler> resource_scheduler_;
    std::unique_ptr<RpcCommunicationModule> rpc_communication_module_;
};

#endif // CENTRAL_SERVER_H
