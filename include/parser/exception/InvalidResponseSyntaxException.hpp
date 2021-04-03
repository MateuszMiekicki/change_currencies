#ifndef InvalidResponseSyntaxException_hpp
#define InvalidResponseSyntaxException_hpp

#include <exception>
#include <string>

class InvalidResponseSyntaxException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

#endif