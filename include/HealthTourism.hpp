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
#include <string>

class HealthTourism
{
public:
    // HealthTourism();
    // ~HealthTourism();
    void run();
    User *signup(std::string username, std::string password, std::string email, std::string type);
    void check_user_existence(std::string username);
    User *find_user(std::string username);
    User *find_user_by_id(std::string id);
    User *login(std::string username, std::string password);
    void delete_request(std::string id);
    void set_supporter(std::string id);
    std::vector<std::string> get_names_info(std::string id);
    void check_for_available_supporter();
    // void add_package(Patient *pt, std::string name, std::string cost);

private:
    std::vector<User *> users;
    std::vector<Supporter *> supporters;
    int patient_id = 1;
    int supporter_id = 1;
};

#endif