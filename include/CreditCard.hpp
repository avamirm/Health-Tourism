#ifndef CREDITCARD_HPP
#define CREDITCARD_HPP

#include <string>
#include <sstream>
#include "../include/date.hpp"

class CreditCard
{
public:
    CreditCard(std::string _card_number, std::string _expiration_date, std::string _cvv);
    ~CreditCard();
    bool is_valid();
    std::string get_card_number();
    std::string get_expiration_date();
    std::string get_cvv();

private:
    std::string card_number;
    std::string expiration_date;
    // std::istringstream ss(expiration_date);
    std::string cvv;
};

#endif