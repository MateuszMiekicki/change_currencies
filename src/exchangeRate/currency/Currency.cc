#include "exchangeRate/currency/Currency.hpp"
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

Currency::Currency(const char *code) : _code{code}
{
    std::transform(_code.begin(),
                   _code.end(),
                   _code.begin(),
                   ::toupper);
}

Currency::Currency(const std::string &code) : _code{code}
{
    std::transform(_code.begin(),
                   _code.end(),
                   _code.begin(),
                   ::toupper);
}

void Currency::setCode(const std::string &code)
{
    _code = code;
    std::transform(_code.begin(),
                   _code.end(),
                   _code.begin(),
                   ::toupper);
}

std::string Currency::getCode() const
{
    return _code;
}

bool Currency::operator==(const Currency &other) const
{
    return _code == other._code;
}

std::size_t std::hash<Currency>::operator()(const Currency &Currency) const noexcept
{
    return std::hash<std::string>{}(Currency.getCode());
}
