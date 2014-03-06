#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>
class QueryExceptions:public std::runtime_error
{
public:
    QueryExceptions(const std::string& message):std::runtime_error(message){}
};

#endif // EXCEPTIONS_H
