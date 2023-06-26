#include "resource_manager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    std::cout << "ResourceManager constructor called." << std::endl;
}

ResourceManager::~ResourceManager()
{
    std::cout << "ResourceManager destructor called." << std::endl;
}
