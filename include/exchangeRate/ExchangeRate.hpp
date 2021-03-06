#ifndef ExchangeRate_hpp
#define ExchangeRate_hpp

#include "Rate.hpp"
#include "amount/Amount.hpp"
#include "currency/Currency.hpp"
#include <utility>

class ExchangeRate
{
private:
    std::pair<Currency, Rate> _toExchangeRate;
    std::pair<Currency, Rate> _fromExchangeRate;

public:
    ExchangeRate() = default;
    ExchangeRate(const std::pair<Currency, Rate> &toExchangeRate,
                 const std::pair<Currency, Rate> &fromExchangeRate);
    ExchangeRate(const ExchangeRate &exchangeRate) = default;
    ExchangeRate &operator=(const ExchangeRate &exchangeRate) = default;
    ExchangeRate(ExchangeRate &&exchangeRate) = default;
    ExchangeRate &operator=(ExchangeRate &&exchangeRate) = default;

    void setToExchangeRate(const std::pair<Currency, Rate> &toExchangeRate);
    std::pair<Currency, Rate> getToExchangeRate() const;
    void setFromExchangeRate(const std::pair<Currency,
                                             Rate> &fromExchangeRate);
    std::pair<Currency, Rate> getFromExchangeRate() const;
};

#endif