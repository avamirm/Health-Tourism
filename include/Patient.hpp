#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "User.hpp"
#include "CreditCard.hpp"
#include "exceptions.hpp"

class Patient : public User
{
public:
    Patient(std::string _username, std::string _password, std::string _email, int _id);
    ~Patient();
    std::string get_type() override;
    std::string get_id() override;
    std::string get_supporter_name();
    bool is_pending();
    void add_request(std::string chosen_package, std::string cost);
    void delete_request();
    void set_request_date(std::string date);
    void set_request_file(std::string file);
    void set_request_card_number(std::string card_number, std::string expiry_date, std::string cvv);
    // void set_supporter(Supporter *supporter);
    int get_request_cost();
    std::string get_request_package_id();
    Requests *get_request();

private:
    std::string sessoion_id;
    std::vector<Requests *> requests;
    std::vector<CreditCard *> credit_cards;
};

#endif