#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

constexpr char INVALID_ENTRY[] = "Invalid Entry!";
constexpr char NOT_EXIST[] = "Not Exist!";
constexpr char INCORRECT_PASSWORD[] = "Incorrect Password!";

class InvalidEntry : public std::exception
{
public:
    const char *what() const noexcept { return INVALID_ENTRY; }
};

class NotExist : public std::exception
{
public:
    const char *what() const noexcept { return NOT_EXIST; }
};

class IncorrectPassword : public std::exception
{
public:
    const char *what() const noexcept { return INCORRECT_PASSWORD; }
};

#endif