#include "../include/Patient.hpp"

Patient::Patient(std::string _username, std::string _password, std::string _email)
    : User(_username, _password, _email) {}

std::string Patient::get_type()
{
    return "Patient";
}