#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../server/server.hpp"
#include "../include/exceptions.hpp"
#include "../include/User.hpp"
#include "../include/HealthTourism.hpp"
#include <exception>
#include <string>

class HealthTourism;

class SignupHandler : public RequestHandler
{
public:
    SignupHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class LoginHandler : public RequestHandler
{
public:
    LoginHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

#endif