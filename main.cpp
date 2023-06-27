#include "central_server.h"
#include <iostream>
#include <signal.h>
#include <atomic>
#include <thread>
#include <chrono>

std::atomic<bool> running(true);

void signalHandler(int signal)
{
    std::cout << "Received signal " << signal << ". Shutting down..." << std::endl;
    running = false;
}

int main()
{

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    CentralServer centralServer;
    std::cout << "CentralServer started. Listening for connections..." << std::endl;

    while (running)
    {

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "CentralServer is shutting down..." << std::endl;
    centralServer.shutdown();
    return 0;
}
