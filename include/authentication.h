#ifndef AUTHENTICATION_MODULE_H
#define AUTHENTICATION_MODULE_H

#include <string>

class AuthenticationModule
{
public:
    AuthenticationModule();
    ~AuthenticationModule();

    // User Registration via Wallet Address
    bool registerUser(const std::string &walletAddress);

    // User Authentication
    bool authenticateUser(const std::string &walletAddress);

    // Wallet to GPU Binding
    bool bindWalletToGPU(const std::string &walletAddress, const std::string &gpuID);

    // Permission Management
    bool setUserPermissions(const std::string &walletAddress, int permissions);

    // ...add more methods and members as needed.
};

#endif // AUTHENTICATION_MODULE_H
