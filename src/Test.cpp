#include "../include/Test.hpp"

bool Test::test_add_request()
{
    Patient* p = new Patient("username", "password", "email", 1);
    std::string chosen_package = "1";
    std::string cost = "1100";
    p->add_request(chosen_package, cost);
    Requests* req = new Requests(chosen_package, "Pending", "", cost, nullptr);
    if (*(p->get_request()) == *req) 
        return true;
    return false;
}

bool Test::test_set_not_existed_supporter(HealthTourism* ht)
{
    try 
    {
        ht->set_supporter("2");
    }
    catch (NotExist)
    {
        return true;
    }
    return false;
}

bool Test::test_set_existed_supporter(HealthTourism* ht)
{
    try 
    {
        ht->set_supporter("P1");
        return true;
    }
    catch (NotExist)
    {
        return false;
    }
}

bool Test::test_set_supporter()
{

    HealthTourism* ht = new HealthTourism();
    std::string chosen_package = "1";
    std::string cost = "1100";
    std::string username  = "username";
    std::string password = "password";
    std::string email = "email";
    std::string address = "";
    std::string supporter_username = "sUsername";
    std::string supporter_password = "sPassword";
    std::string supporter_email = "sEmail";
    std::string supporter_address = "sAddress";

    User* p = ht->signup(username, password, email, address);
    Requests* req = new Requests(chosen_package, "Pending", "", cost, nullptr);
    static_cast<Patient *>(p)->add_request(chosen_package, cost);
    ht->signup(supporter_username, supporter_password, supporter_email, supporter_address);
    return (test_set_existed_supporter(ht) && test_set_not_existed_supporter(ht));
}


void Test::run()
{
    if (test_add_request())
        std::cout << "testAddRequest passed" << std::endl;
    else
        std::cout << "testAddRequest failed" << std::endl;
    if (test_set_supporter())
        std::cout << "testSetSupporter passed" << std::endl;
    else
        std::cout << "testSetSupporter failed" << std::endl;    
    return;
}