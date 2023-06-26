#include "authentication.h"
#include <iostream>

AuthenticationModule::AuthenticationModule()
{
    std::cout << "AuthenticationModule constructor called." << std::endl;
}

AuthenticationModule::~AuthenticationModule()
{
    std::cout << "AuthenticationModule destructor called." << std::endl;
}
