#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "string"
#include "date.hpp"

class Request
{
public:
private:
    std::string status;
    std::string date;
    // std::istringstream ss(date);
    int estimated_cost;
};

#endif