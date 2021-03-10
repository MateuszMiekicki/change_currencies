#include "exchangeRate/amount/Amount.hpp"
#include <cmath>

Amount::Amount(const double amount) : _amount{std::abs(amount)}
{
}

void Amount::setAmount(const double amount)
{
    _amount = std::abs(amount);
}

double Amount::getAmount() const
{
    return _amount;
}

bool Amount::operator==(const double other) const
{
    return _amount == other;
}
