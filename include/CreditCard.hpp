#ifndef CREDITCARD_HPP
#define CREDITCARD_HPP

#include "string"
#include "../include/date.hpp"

class CreditCard
{
public:
private:
    std::string card_number;
    std::string expiration_date;
    // std::istringstream ss(expiration_date);
    std::string cvv;
};

#endif