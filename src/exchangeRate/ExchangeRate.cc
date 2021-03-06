#include "exchangeRate/ExchangeRate.hpp"
#include "exchangeRate/Rate.hpp"
#include "exchangeRate/amount/Amount.hpp"
#include "exchangeRate/currency/Currency.hpp"
#include <utility>

ExchangeRate::ExchangeRate(const std::pair<Currency, Rate> &toExchangeRate,
                           const std::pair<Currency, Rate> &fromExchangeRate)
    : _toExchangeRate{toExchangeRate},
      _fromExchangeRate{fromExchangeRate}
{
}

void ExchangeRate::setToExchangeRate(const std::pair<Currency,
                                                     Rate> &toExchangeRate)
{
    _toExchangeRate = toExchangeRate;
}

std::pair<Currency, Rate> ExchangeRate::getToExchangeRate() const
{
    return _toExchangeRate;
}

void ExchangeRate::setFromExchangeRate(const std::pair<Currency,
                                                       Rate> &fromExchangeRate)
{
    _fromExchangeRate = fromExchangeRate;
}

std::pair<Currency, Rate> ExchangeRate::getFromExchangeRate() const
{
    return _fromExchangeRate;
}