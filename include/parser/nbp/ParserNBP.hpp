#ifndef ParserNBP_hpp
#define ParserNBP_hpp

#include "../../exchangeRate/Rate.hpp"
#include "../../exchangeRate/currency/Currency.hpp"
#include "date/date.h"
#include "parser/Parser.hpp"
#include "rapidjson/document.h"
#include <string>
#include <unordered_map>

class ParserNBP : public Parser
{
private:
    std::unordered_map<Currency, Rate> _data;
    date::year_month_day _effectiveDate;
    void validateSyntax(const rapidjson::Document &json);

public:
    virtual std::unordered_map<Currency,
                               Rate>
    parse(const std::string &argument) override;
    virtual date::year_month_day getEffectiveDate() const override;
    virtual std::unordered_map<Currency, Rate> getResult() const override;
};

#endif