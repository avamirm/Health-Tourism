#include "../include/Requests.hpp"
#include "../include/Supporter.hpp"

Requests::Requests(std::string _name, std::string _status, std::string _date, std::string _estimated_cost, Supporter *_supporter)
{
    name = _name;
    status = _status;
    date = _date;
    estimated_cost = _estimated_cost;
    std::cout << "___est cost::: " << _estimated_cost << "est cost:: --- " << estimated_cost << std::endl;
    supporter = _supporter;
}

Requests::~Requests()
{
}

void Requests::set_date(std::string _date)
{
    date = _date;
}

void Requests::set_file(std::string file)
{
    MedicalDocument *md = new MedicalDocument(file, name, false);
    medical_documents.push_back(md);
}

std::string Requests::get_status()
{
    return status;
}

int Requests::get_estimated_cost()
{
    return std::stoi(estimated_cost) * 0.2;
}

std::string Requests::get_package_id()
{
    return name;
}

std::string Requests::get_package_status()
{
    return status;
}

std::string Requests::get_package_date()
{
    return date;
}

std::string Requests::get_supporter_name()
{
    std::string name = supporter->get_name();
    return name;
}

void Requests::change_status(std::string _status)
{
    status = _status;
}

void Requests::assigned_supporter(Supporter *_supporter)
{
    supporter = _supporter;
    supporter->change_status();
    change_status("Pending");
}
