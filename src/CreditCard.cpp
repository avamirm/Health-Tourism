#include "../include/CreditCard.hpp"

CreditCard::CreditCard(std::string _card_number, std::string _expiration_date, std::string _cvv)
{
    card_number = _card_number;
    expiration_date = _expiration_date;
    cvv = _cvv;
}

CreditCard::~CreditCard()
{
}

bool CreditCard::is_valid()
{
    std::istringstream ss(expiration_date);
    date::year_month_day resultDate;
    ss >> date::parse("%M-%d", resultDate); // %F: %Y-%M-%d
    if (ss.fail() || card_number.length() != 16 || cvv.length() != 3)
        return false;
    return true;
}