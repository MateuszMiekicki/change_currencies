#ifndef Parser_hpp
#define Parser_hpp

#include "../exchangeRate/Rate.hpp"
#include "../exchangeRate/currency/Currency.hpp"
#include <string>
#include <utility>
#include <vector>

class Parser
{
public:
    virtual std::vector<std::pair<Currency,
                                  Rate>>
    parse(const std::string &argument) = 0;
    virtual std::vector<std::pair<Currency, Rate>> getResult() const = 0;
    virtual ~Parser(){};
};

#endif