#include "Currency.hpp"
#include <string>

Currency::Currency(const std::string &code) : _code{code}
{
}

void Currency::setCode(const std::string &code)
{
    _code = code;
}

std::string Currency::getCode() const
{
    return _code;
}
