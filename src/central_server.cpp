#include "central_server.h"
#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <fstream>   // For file I/O
#include <stdexcept> // For exceptions

CentralServer::CentralServer() : port_(8080),
                                 running(false),
                                 authentication_module_(new AuthenticationModule()),
                                 resource_manager_(new ResourceManager()),
                                 task_queue_manager_(new TaskQueueManager()),
                                 resource_scheduler_(new ResourceScheduler()),
                                 rpc_communication_module_(new RpcCommunicationModule())
{
}

CentralServer::~CentralServer()
{
    // Nothing to do here.
    // shutdown() should be called explicitly before the object is destructed.
}

void CentralServer::start()
{
    std::string rpcAddress = "127.0.0.1"; // RPC server address
    int rpcPort = 9090;                   // RPC server port

    running = true;
    std::cout << "CentralServer started. Listening for connections on port " << port_ << "..." << std::endl;

    std::ofstream logfile("central-server/logs/gpu_info.log", std::ios::app);
    if (!logfile.is_open())
    {
        throw std::runtime_error("Failed to open log file.");
    }

    while (running)
    {
        try
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::string gpuInfo = rpc_communication_module_->connectAndRetrieveGpuInfo(rpcAddress, rpcPort);
            std::cout << "RPC Server GPU Info: " << gpuInfo << std::endl;

            // Write GPU info to log file
            logfile << "GPU Info: " << gpuInfo << std::endl;
            logfile.flush();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void CentralServer::shutdown()
{
    running = false;

    if (rpc_communication_module_)
    {
        rpc_communication_module_->disconnect();
    }

    // Additional cleanup operations if needed
}
