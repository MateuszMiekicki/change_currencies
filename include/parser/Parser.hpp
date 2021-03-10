#ifndef Parser_hpp
#define Parser_hpp

#include "../exchangeRate/Rate.hpp"
#include "../exchangeRate/currency/Currency.hpp"
#include <string>
#include <unordered_map>

class Parser
{
public:
    virtual std::unordered_map<Currency,
                               Rate>
    parse(const std::string &argument) = 0;
    virtual std::unordered_map<Currency, Rate> getResult() const = 0;
    virtual ~Parser(){};
};

#endif