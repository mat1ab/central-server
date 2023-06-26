#pragma once

#include <string>

class RpcCommunicationModule {
public:
    RpcCommunicationModule();
    ~RpcCommunicationModule();

    std::string connectAndRetrieveGpuInfo(const std::string &rpcAddress, int rpcPort);

private:
    int clientSocket;
};
