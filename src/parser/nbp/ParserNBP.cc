#include "parser/nbp/ParserNBP.hpp"
#include "date/date.h"
#include "exchangeRate/Rate.hpp"
#include "exchangeRate/currency/Currency.hpp"
#include "parser/exception/InvalidResponseSyntaxException.hpp"
#include "rapidjson/document.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<Currency, Rate> ParserNBP::parse(const std::string &argument)
{
    rapidjson::Document json;
    json.Parse(argument.c_str());
    validateSyntax(json);
    auto effectiveDate{json.GetArray()[0]
                           .FindMember("effectiveDate")
                           ->value.GetString()};
    auto splitStringOnYYYY_MM_DD = [](const std::string &date) {
        auto year = std::stoi(date.substr(0, 4));
        auto month = std::stoi(date.substr(5, 7));
        auto day = std::stoi(date.substr(8, 11));
        return date::year{year} / month / day;
    };
    _effectiveDate = splitStringOnYYYY_MM_DD(effectiveDate);
    auto rates{json.GetArray()[0].FindMember("rates")->value.GetArray()};
    _data.reserve(rates.Size());

    for (auto itr{rates.Begin()};
         itr != rates.End();
         ++itr)
    {
        const rapidjson::Value &object{*itr};
        auto code = std::string(object
                                    .GetObject()
                                    .FindMember("code")
                                    ->value.GetString());
        std::transform(code.begin(),
                       code.end(),
                       code.begin(),
                       ::toupper);
        auto bid = object.GetObject().FindMember("bid")->value.GetDouble();
        auto ask = object.GetObject().FindMember("ask")->value.GetDouble();
        _data.emplace(Currency{code}, Rate{bid, ask});
    }
    return _data;
}

date::year_month_day ParserNBP::getEffectiveDate() const
{
    return _effectiveDate;
}

std::unordered_map<Currency, Rate> ParserNBP::getResult() const
{
    return _data;
}

void ParserNBP::validateSyntax(const rapidjson::Document &json)
{
    if (!json.IsArray())
    {
        throw InvalidResponseSyntaxException();
    }
    if (!json.GetArray()[0].HasMember("effectiveDate"))
    {
        throw InvalidResponseSyntaxException();
    }
    if (!json.GetArray()[0].HasMember("rates"))
    {
        throw InvalidResponseSyntaxException();
    }
    auto rates = json.GetArray()[0].FindMember("rates");
    if (!rates->value.IsArray())
    {
        throw InvalidResponseSyntaxException();
    }
    for (const auto &rate : rates->value.GetArray())
    {
        if (!rate.HasMember("bid") || !rate.HasMember("ask"))
        {
            throw InvalidResponseSyntaxException();
        }
    }
}
