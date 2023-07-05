#include "../include/HealthTourism.hpp"

// HealthTourism::~HealthTourism()
// {
//     for (User *user : users)
//         delete user;
// }

void HealthTourism::run()
{
    Server server(5000);
    server.get("/doc-0.png", new ShowImage("static/assets/doc-0.png"));
    server.get("/doc-1.png", new ShowImage("static/assets/doc-1.png"));
    server.get("/doc-2.png", new ShowImage("static/assets/doc-2.png"));
    server.get("/doc-3.png", new ShowImage("static/assets/doc-3.png"));
    server.get("/doc-4.png", new ShowImage("static/assets/doc-4.png"));
    server.get("/doc-5.png", new ShowImage("static/assets/doc-5.png"));
    server.get("/doc-6.png", new ShowImage("static/assets/doc-6.png"));
    server.get("/doc-7.png", new ShowImage("static/assets/doc-7.png"));
    server.get("/doc-8.png", new ShowImage("static/assets/doc-8.png"));

    server.get("/header-doc-img.png", new ShowImage("static/assets/header-doc-img.png"));
    server.get("/why-doc-img.png", new ShowImage("static/assets/why-doc-img.png"));
    server.get("/why-doc-img-2.svg", new ShowImage("static/assets/why-doc-img-2.svg"));
    server.get("/WeCare-Logo.png", new ShowImage("static/assets/WeCare-Logo.png"));
    server.get("/Error.jpg", new ShowImage("static/assets/Error.jpg"));

    server.get("/", new ShowPage("static/Home.html"));
    server.get("/Home", new ShowPage("static/Home.html"));
    server.get("/formalize.css", new ShowPage("static/formalize.css"));
    server.get("/home.css", new ShowPage("static/home.css"));

    server.get("/Signup", new ShowPage("static/Signup.html"));
    server.get("/Signup_login.css", new ShowPage("static/Signup_login.css"));
    server.post("/Signup", new SignupHandler(this));
    server.get("/Login", new ShowPage("static/Login.html"));
    server.post("/Login", new LoginHandler(this));
    server.get("/Logout", new LogoutHandler(this));
    server.get("/Error", new ShowPage("static/Error.html"));
    server.get("/Package", new ShowPage("static/Package.html"));
    server.post("/Package", new AddPackageHandler(this));
    // server.get("/", new ShowPage("static/PackageForm.html"));
    server.get("/AddRequest", new ShowPage("static/PackageForm.html"));
    server.get("/PackageForm.css", new ShowPage("static/PackageForm.css"));
    server.post("/AddRequest", new AddRequestHandler(this));
    server.get("/PaymentInfo", new PaymentInfoHandler("static/PaymentInfo.html", this));
    server.get("/Payment", new ShowPage("static/Payment.html"));
    server.post("Payment", new PaymentHandler(this));
    server.get("/SuccessPayment", new ShowPage("static/SuccessPayment.html"));
    server.post("/SuccessPayment", new SuccessPaymentHandler(this));
    server.get("/success-icon.png", new ShowImage("static/assets/success-icon.png"));
    server.get("/SuccessSendingInfo", new SendingInfoHandler("static/SuccessSendingInfo.html", this));
    // server.get("/SuccessSendingInfo", new ShowPage("static/SuccessSendingInfo.html"));
    server.run();
}

User *HealthTourism::find_user_by_id(std::string id)
{
    for (User *user : users)
        if (user->get_id() == id)
            return user;
    return nullptr;
}

User *HealthTourism::find_user(std::string username)
{
    for (User *user : users)
        if (user->get_username() == username)
            return user;
    return nullptr;
}

void HealthTourism::check_user_existence(std::string username)
{
    if (find_user(username) != nullptr)
        throw NotExist();
}

User *HealthTourism::signup(std::string username, std::string password, std::string email, std::string address)
{
    check_user_existence(username);
    User *user;
    if (address == "")
        user = new Patient(username, password, email, patient_id++);
    else
    {
        user = new Supporter(username, password, email, (rand() % 10) + 1, address, supporter_id++);
        supporters.push_back(static_cast<Supporter *>(user));
    }
    users.push_back(user);
    return user;
}

User *HealthTourism::login(std::string username, std::string password)
{
    User *user = find_user(username);
    if (user == nullptr)
        throw NotExist();
    if (user->get_password() != password)
        throw IncorrectPassword();
    return user;
}

void HealthTourism::set_supporter(std::string id)
{
    User *user = find_user_by_id(id);
    if (user == nullptr)
        throw NotExist();
    for (Supporter *supporter : supporters)
    {
        if (!supporter->is_assigned())
        {
            Requests *req = static_cast<Patient *>(user)->get_request();
            req->change_status("Waiting For Supporter");
            req->assigned_supporter(supporter);
            return;
        }
    }
    throw NotExist();
}

std::vector<std::string> HealthTourism::get_names_info(std::string id)
{
    User *user = find_user_by_id(id);
    Requests *req = static_cast<Patient *>(user)->get_request();
    std::string sup_name = req->get_supporter_name();
    std::cout << "sup name func: " << sup_name << std::endl;
    std::string pt_name = static_cast<Patient *>(user)->get_username();
    std::vector<std::string> strings = {sup_name, pt_name};
    return strings;
}

void HealthTourism::check_for_available_supporter()
{
    for (Supporter *supporter : supporters)
    {
        if (!supporter->is_assigned())
        {
            return;
        }
    }
    throw NotExist();
}