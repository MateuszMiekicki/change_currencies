#include "exchangeRate/Rate.hpp"
#include "exchangeRate/amount/Amount.hpp"

Rate::Rate(const Amount &bid, const Amount &ask) : _bid{bid},
                                                   _ask{ask}
{
}

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