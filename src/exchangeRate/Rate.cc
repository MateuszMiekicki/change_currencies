#include "exchangeRate/Rate.hpp"
#include "exchangeRate/amount/Amount.hpp"

void Rate::setBid(const Amount &bid)
{
    _bid = bid;
}

Amount Rate::getBid() const
{
    return _bid;
}

void Rate::setAsk(const Amount &ask)
{
    _ask = ask;
}

Amount Rate::getAsk() const
{
    return _ask;
}