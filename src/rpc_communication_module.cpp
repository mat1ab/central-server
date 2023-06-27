#include "rpc_communication_module.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <cerrno>
#include <stdexcept> // For standard exceptions

RpcCommunicationModule::RpcCommunicationModule()
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        throw std::runtime_error("Failed to create socket: " + std::string(std::strerror(errno)));
    }
}

RpcCommunicationModule::~RpcCommunicationModule()
{
    disconnect();
}

std::string RpcCommunicationModule::connectAndRetrieveGpuInfo(const std::string &rpcAddress, int rpcPort)
{
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(rpcPort);

    if (inet_pton(AF_INET, rpcAddress.c_str(), &serverAddress.sin_addr) <= 0)
    {
        throw std::runtime_error("Invalid address/Address not supported");
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        throw std::runtime_error("Failed to connect to RPC: " + std::string(std::strerror(errno)));
    }

    const std::string request = "get_gpu_info";
    if (send(clientSocket, request.c_str(), request.size(), 0) < 0)
    {
        throw std::runtime_error("Failed to send request: " + std::string(std::strerror(errno)));
    }

    char buffer[256];
    memset(buffer, 0, 256);
    ssize_t bytesRead = read(clientSocket, buffer, 255);

    if (bytesRead < 0)
    {
        throw std::runtime_error("Failed to read response: " + std::string(std::strerror(errno)));
    }
    else if (bytesRead == 0)
    {
        throw std::runtime_error("Connection closed by RPC");
    }

    return std::string(buffer);
}

void RpcCommunicationModule::disconnect()
{
    if (clientSocket != -1)
    {
        close(clientSocket);
        clientSocket = -1;
        std::cout << "Disconnected from RPC server." << std::endl;
    }
}
