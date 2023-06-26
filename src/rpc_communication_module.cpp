#include "rpc_communication_module.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

RpcCommunicationModule::RpcCommunicationModule() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Failed to create socket" << std::endl;
    }
}

RpcCommunicationModule::~RpcCommunicationModule() {
    close(clientSocket);
}

std::string RpcCommunicationModule::connectAndRetrieveGpuInfo(const std::string &rpcAddress, int rpcPort) {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(rpcPort);
    inet_pton(AF_INET, rpcAddress.c_str(), &serverAddress.sin_addr);

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Failed to connect to RPC" << std::endl;
        return "";
    }

    const std::string request = "get_gpu_info";
    send(clientSocket, request.c_str(), request.size(), 0);

    char buffer[256];
    memset(buffer, 0, 256);
    read(clientSocket, buffer, 255);

    return std::string(buffer);
}
