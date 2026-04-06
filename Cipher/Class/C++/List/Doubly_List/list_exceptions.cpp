#ifndef LIST_EXCEPTIONS_HPP
#define LIST_EXCEPTIONS_HPP

#include <exception>

class list_empty : public std::exception
{
private:
    const char* msg;

public:
    list_empty(const char* _msg) : msg(_msg) {}

    const char* what() const noexcept
    {
        return msg;
    }
};

class list_data_not_found : public std::exception
{
private:
    const char* msg;

public:
    list_data_not_found(const char* _msg) : msg(_msg) {}

    const char* what() const noexcept
    {
        return msg;
    }
};

#endif