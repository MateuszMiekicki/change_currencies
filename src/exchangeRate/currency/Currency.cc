#include "exchangeRate/currency/Currency.hpp"
#include <functional>
#include <string>

Currency::Currency(const char *code) : _code{code}
{
}

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

bool Currency::operator==(const Currency &other) const
{
    return _code == other._code;
}

std::size_t std::hash<Currency>::operator()(const Currency &Currency) const noexcept
{
    return std::hash<std::string>{}(Currency.getCode());
}
