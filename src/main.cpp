#include <iostream>

#include "../include/HealthTourism.hpp"
#include "../include/Test.hpp"

int main(int argc, char* argv[])
{
    if (argc == 2 && std::string(argv[1]) == "test")
    {
        Test test;
        test.run();
        return 0;
    }
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