#include "../include/Handler.hpp"
#include "../include/HealthTourism.hpp"

Response *SignupHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string username = req->getBodyParam("username");
    std::string password = req->getBodyParam("password");
    std::string email = req->getBodyParam("email");
    std::string address = req->getBodyParam("address");
    try
    {
        User *user = health_tourism->signup(username, password, email, address);
        if (address == "")
            res = Response::redirect("/PatientProf");
        else
            res = Response::redirect("/SupporterProf");
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
}

Response *LoginHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string username = req->getBodyParam("username");
    std::string password = req->getBodyParam("password");
    try
    {
        User *user = health_tourism->login(username, password);
        if (user->get_type() == "Patient")
            res = Response::redirect("/PatientProf");
        else
            res = Response::redirect("/SupporterProf");
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
}