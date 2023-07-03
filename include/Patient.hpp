#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "string"
#include "User.hpp"

class Patient : public User
{
public:
    Patient(std::string _username, std::string _password, std::string _email);
    ~Patient();
    virtual std::string get_type() override;
private:

};

#endif