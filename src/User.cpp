#include "../include/User.hpp"

User::User(std::string _username, std::string _password, std::string _email) {
    username = _username;
    password = _password;
    email = _email;
}

User::~User() {

}

std::string User::get_username() {
    return username;
}

std::string User::get_password() {
    return password;
}

std::string User::get_email() {
    return email;
}