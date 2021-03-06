#ifndef Currency_hpp
#define Currency_hpp

#include <functional>
#include <string>

class Currency
{
private:
    std::string _code;

public:
    Currency() = default;
    Currency(const char *code);
    Currency(const std::string &code);
    Currency(const Currency &currency) = default;
    Currency &operator=(const Currency &currency) = default;
    Currency(Currency &&currency) = default;
    Currency &operator=(Currency &&currency) = default;

    void setCode(const std::string &code);
    std::string getCode() const;

    bool operator==(const Currency &other) const;
};

template <>
struct std::hash<Currency>
{
    std::size_t operator()(const Currency &Currency) const noexcept;
};

#endif