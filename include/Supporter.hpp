#ifndef SUPPORTER_HPP
#define SUPPORTER_HPP

#include <string>
#include "../include/User.hpp"

class Supporter : public User
{
public:
    Supporter(std::string _username, std::string _password, std::string _email, int _rate, std::string _address, int _id);
    ~Supporter();
    int get_rate();
    bool get_status() { return assigned;}
    std::string get_name();
    std::string get_address();
    std::string get_password();
    std::string get_type() override;
    std::string get_id() override;
    bool is_assigned();
    void change_status();

private:
    int rate;
    std::string address;
    std::string session_id;
    bool assigned = false;
};

#endif
