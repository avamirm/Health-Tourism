#ifndef SUPPORTER_HPP
#define SUPPORTER_HPP

#include "User.hpp"
#include "string"

class Supporter : public User {
public:
    Supporter(std::string _username, std::string _password, std::string _email, int _rate, std::string _address);
    ~Supporter();
    int get_rate();
    std::string get_address();
    virtual std::string get_type() override;
private:
    int rate;
    std::string address;
};

#endif