#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../server/server.hpp"
#include "../include/exceptions.hpp"
#include "../include/User.hpp"
#include "../include/HealthTourism.hpp"
#include <exception>
#include <string>
#include <chrono>
#include <thread>

class HealthTourism;

class ShowFileJs : public RequestHandler
{
public:
    ShowFileJs(const std::string &path);
    Response *callback(Request *req) override;

private:
    std::string path_;
};

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

class LogoutHandler : public RequestHandler
{
public:
    LogoutHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class AddPackageHandler : public RequestHandler
{
public:
    AddPackageHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class AddRequestHandler : public RequestHandler
{
public:
    AddRequestHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class PaymentInfoHandler : public TemplateHandler
{
public:
    PaymentInfoHandler(const std::string &filePath, HealthTourism *_ht) : TemplateHandler(filePath), health_tourism(_ht){};
    std::map<std::string, std::string> handle(Request *req) override;
private:
    HealthTourism *health_tourism;
};

class PaymentHandler : public RequestHandler
{
public:
    PaymentHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class SuccessPaymentHandler : public RequestHandler
{
public:
    SuccessPaymentHandler(HealthTourism *_ht) : health_tourism(_ht){};
    Response *callback(Request *);

private:
    HealthTourism *health_tourism;
};

class SendingInfoHandler : public TemplateHandler
{
public:
    SendingInfoHandler(const std::string &filePath, HealthTourism *_ht) : TemplateHandler(filePath), health_tourism(_ht){};
    std::map<std::string, std::string> handle(Request *req) override;

private:
    HealthTourism *health_tourism;
};
#endif