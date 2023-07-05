#include <iostream>

#include "../include/HealthTourism.hpp"

int main()
{
    try
    {
        HealthTourism healthTourism;
        healthTourism.run();
    }
    catch (Server::Exception &e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
}