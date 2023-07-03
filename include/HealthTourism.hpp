#ifndef HEALTHTOURISM_HPP
#define HEALTHTOURISM_HPP

#include "../server/server.hpp"
#include "../include/exceptions.hpp"
#include "../include/User.hpp"
#include "../include/Patient.hpp"
#include "../include/Supporter.hpp"
#include "../include/Handler.hpp"

#include <vector>
#include <iostream>

class HealthTourism
{
public:
    HealthTourism();
    ~HealthTourism();
    void run();
    User *signup(std::string username, std::string password, std::string email, std::string type);
    void checkUserExistence(std::string username);
    User *findUser(std::string username);
    User *login(std::string username, std::string password);

private:
    std::vector<User *> users;
};

#endif