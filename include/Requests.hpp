#ifndef REQUESTS_HPP
#define REQUESTS_HPP

#include <string>
#include <vector>
#include <iostream>
#include "date.hpp"
#include "MedicalDocument.hpp"
// #include "Supporter.hpp"

class Supporter;

class Requests
{
public:
    Requests(std::string name, std::string _status, std::string _date, std::string _estimated_cost, Supporter *_supporter);
    ~Requests();
    std::string get_status();
    int get_estimated_cost();
    std::string get_supporter_name();
    void change_status(std::string _status);
    void change_estimated_cost(int _estimated_cost);
    void assigned_supporter(Supporter *_supporter);
    void set_date(std::string _date);
    void set_file(std::string file);
    std::string get_package_id();
    std::string get_package_status();
    std::string get_package_date();

private:
    std::string name;
    std::string status;
    std::string date;
    // std::istringstream ss(date);
    std::string estimated_cost;
    Supporter *supporter;
    std::vector<MedicalDocument *> medical_documents;
};

#endif
