#include "../include/Supporter.hpp"

Supporter::Supporter(std::string _username, std::string _password, std::string _email, int _rate, std::string _address, int _id)
    : User(_username, _password, _email)
{
    rate = _rate;
    address = _address;
    session_id = "S" + std::to_string(_id);
}

std::string Supporter::get_type()
{
    return "Supporter";
}

std::string Supporter::get_id()
{
    return session_id;
}

int Supporter::get_rate()
{
    return rate;
}

std::string Supporter::get_name()
{
    return username;
}

bool Supporter::is_assigned()
{
    return assigned;
}

void Supporter::change_status()
{
    assigned = !assigned;
}