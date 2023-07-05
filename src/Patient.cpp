#include "../include/Patient.hpp"

Patient::Patient(std::string _username, std::string _password, std::string _email, int _id)
    : User(_username, _password, _email)
{
    sessoion_id = "P" + std::to_string(_id);
}

std::string Patient::get_type()
{
    return "Patient";
}

std::string Patient::get_id()
{
    return sessoion_id;
}

std::string Patient::get_supporter_name()
{
    return requests[requests.size() - 1]->get_supporter_name();
}

bool Patient::is_pending()
{
    std::cout << "req Size: " << requests.size() << std::endl;
    for (Requests *req : requests)
    {
        if (req->get_status() == "Pending" || req->get_status() == "Waiting For Supporter")
            return true;
    }
    return false;
}

void Patient::add_request(std::string chosen_package, std::string cost)
{
    std::cout << "addREq cost-->" << cost << std::endl;
    Requests *req = new Requests(chosen_package, "Pending", "", cost, nullptr);
    requests.push_back(req);
}

void Patient::set_request_date(std::string date)
{
    requests[requests.size() - 1]->set_date(date);
}

void Patient::set_request_file(std::string file)
{
    requests[requests.size() - 1]->set_file(file);
}

void Patient::set_request_card_number(std::string card_number, std::string expiry_date, std::string cvv)
{
    CreditCard *cc = new CreditCard(card_number, expiry_date, cvv);
    if (!cc->is_valid())
        throw IncorrectInput();
    credit_cards.push_back(cc);
}

// void Patient::set_supporter(Supporter *supporter)
// {
//     requests[requests.size() - 1]->change_status("Waiting For Supporter");
//     requests[requests.size() - 1]->assigned_supporter(supporter);
// }

int Patient::get_request_cost()
{
    return requests[requests.size() - 1]->get_estimated_cost();
}

std::string Patient::get_request_package_id()
{
    return requests[requests.size() - 1]->get_package_id();
}

Requests *Patient::get_request()
{
    return requests[requests.size() - 1];
}