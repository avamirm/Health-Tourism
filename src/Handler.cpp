#include "../include/Handler.hpp"
#include "../include/HealthTourism.hpp"

ShowFileJs::ShowFileJs(const std::string &path) : path_(path) {}
Response *ShowFileJs::callback(Request *req)
{
    Response *res = new Response();
    res->setHeader("Content-Type", "text/javascript");
    res->setBody(readFile(path_.c_str()));
    return res;
}

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
        res = Response::redirect("/");
        res->setSessionId(user->get_id());
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
    return res;
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
        {
            // res = Response::redirect("/PatientProf");
            res = Response::redirect("/");
            res->setSessionId(user->get_id());
        }
        else
        {
            // res = Response::redirect("/SupporterProf");
            res = Response::redirect("/");
            res->setSessionId(user->get_id());
        }
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
    return res;
}

Response *LogoutHandler::callback(Request *req)
{
    Response *res = new Response;
    res = Response::redirect("/");
    res->setSessionId("");
    return res;
}

Response *AddPackageHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string id = req->getSessionId();
    User *user = health_tourism->find_user_by_id(id);
    if (id[0] == 'P')
    {
        if (dynamic_cast<Patient *>(user)->is_pending())
        {
            res = Response::redirect("/PendingError");
            return res;
        }
        std::string chosen_package = req->getBodyParam("chosen_package");
        std::string cost = req->getBodyParam("cost");
        std::cout << "cost: " << cost << std::endl;
        std::string package_id = "/AddRequest?id=" + chosen_package;
        dynamic_cast<Patient *>(user)->add_request(chosen_package, cost);
        res = Response::redirect(package_id);
    }
    else
    {
        res = Response::redirect("/Error");
    }
    return res;
}

Response *AddRequestHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string id = req->getSessionId();
    User *user = health_tourism->find_user_by_id(id);
    std::string date = req->getBodyParam("date");
    std::string file = req->getBodyParam("file");
    try
    {
        health_tourism->check_for_available_supporter();
        dynamic_cast<Patient *>(user)->set_request_date(date);
        dynamic_cast<Patient *>(user)->set_request_file(file);
        res = Response::redirect("/PaymentInfo");
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
    return res;
}

std::map<std::string, std::string> PaymentInfoHandler::handle(Request *req)
{
    std::map<std::string, std::string> context;
    std::string id = req->getSessionId();
    User *user = health_tourism->find_user_by_id(id);
    int cost = dynamic_cast<Patient *>(user)->get_request_cost();
    std::string package_id = dynamic_cast<Patient *>(user)->get_request_package_id();
    context["cost"] = std::to_string(cost) + "$";
    context["package_id"] = package_id;
    return context;
}

Response *PaymentHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string id = req->getSessionId();
    User *user = health_tourism->find_user_by_id(id);
    std::string card_number = req->getBodyParam("card_number");
    std::string expiry_date = req->getBodyParam("expiry_date");
    std::string cvv = req->getBodyParam("cvv");
    try
    {
        dynamic_cast<Patient *>(user)->set_request_card_number(card_number, expiry_date, cvv);
        res = Response::redirect("/SuccessPayment");
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
    return res;
}

Response *SuccessPaymentHandler::callback(Request *req)
{
    Response *res = new Response;
    std::string id = req->getSessionId();
    try
    {
        health_tourism->set_supporter(id);
        res = Response::redirect("/SuccessSendingInfo");
    }
    catch (std::exception &e)
    {
        res = Response::redirect("/Error");
    }
    return res;
}

std::map<std::string, std::string> SendingInfoHandler::handle(Request *req)
{
    std::map<std::string, std::string> context;
    std::string id = req->getSessionId();
    std::vector<std::string> result = health_tourism->get_names_info(id);
    context["patient_name"] = result[1];
    context["supporter_name"] = result[0];
    std::cout << "res111: " << result[1] << "REsss 22:" << result[0] << std::endl;
    return context;
}