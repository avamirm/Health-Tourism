#include "../include/HealthTourism.hpp"

void HealthTourism::run()
{
    try
    {
        Server server(5000);
        server.get("/Signup", new ShowPage("static/Signup.html"));
        server.post("/Signup", new SignupHandler(this));
        server.get("/Login", new ShowPage("static/Login.html"));
        server.post("/Login", new LoginHandler(this));
        server.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

User *HealthTourism::findUser(std::string username)
{
    for (User *user : users)
        if (user->get_username() == username)
            return user;
    return nullptr;
}

void HealthTourism::checkUserExistence(std::string username)
{
    if (findUser(username) != nullptr)
        throw NotExist();
}

User *HealthTourism::signup(std::string username, std::string password, std::string email, std::string address)
{
    checkUserExistence(username);
    User *user;
    if (address == "")
        user = new Patient(username, password, email);
    else
        user = new Supporter(username, password, email, 0, address);
    users.push_back(user);
    return user;
}

User *HealthTourism::login(std::string username, std::string password)
{
    User *user = findUser(username);
    if (user == nullptr)
        throw NotExist();
    if (user->get_password() != password)
        throw IncorrectPassword();
    return user;
}