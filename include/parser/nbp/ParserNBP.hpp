#ifndef ParserNBP_hpp
#define ParserNBP_hpp

#include "../../exchangeRate/Rate.hpp"
#include "../../exchangeRate/currency/Currency.hpp"
#include "parser/Parser.hpp"
#include <string>
#include <unordered_map>

class ParserNBP : public Parser
{
private:
    std::unordered_map<Currency, Rate> _data;

public:
    virtual std::unordered_map<Currency,
                               Rate>
    parse(const std::string &argument) override;
    virtual std::unordered_map<Currency, Rate> getResult() const override;
};

#endif