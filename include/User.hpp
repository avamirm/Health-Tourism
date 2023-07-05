#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "../include/Requests.hpp"
// class Requests;

class User
{
public:
    User(std::string _username, std::string _password, std::string _email);
    ~User();
    std::string get_username();
    std::string get_password();
    std::string get_email();
    virtual std::string get_type() = 0;
    virtual std::string get_id() = 0;

protected:
    std::string username;
    std::string password;
    std::string email;
};

#endif