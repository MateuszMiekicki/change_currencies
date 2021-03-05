#ifndef Currency_hpp
#define Currency_hpp

#include <string>

class Currency
{
private:
    std::string _code;

public:
    Currency() = default;
    Currency(const std::string &code);
    Currency(const Currency &currency) = default;
    Currency &operator=(const Currency &currency) = default;
    Currency(Currency &&currency) = default;
    Currency &operator=(Currency &&currency) = default;

    void setCode(const std::string &code);
    std::string getCode() const;
};

#endif