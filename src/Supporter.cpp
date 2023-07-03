#include "../include/Supporter.hpp"

Supporter::Supporter(std::string _username, std::string _password, std::string _email, int _rate, std::string _address)
    : User(_username, _password, _email)
{
    rate = _rate;
    address = _address;
}

std::string Supporter::get_type()
{
    return "Supporter";
}