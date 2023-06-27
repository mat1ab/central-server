#pragma once

#include <string>

class RpcCommunicationModule
{
public:
    RpcCommunicationModule();
    ~RpcCommunicationModule();

    std::string connectAndRetrieveGpuInfo(const std::string &rpcAddress, int rpcPort);

    // Disconnect from the server and close the socket
    void disconnect();

private:
    int clientSocket;
};
