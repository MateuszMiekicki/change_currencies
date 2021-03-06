#ifndef Rate_hpp
#define Rate_hpp

#include "amount/Amount.hpp"

class Rate
{
private:
    Amount _bid;
    Amount _ask;

public:
    Rate() = default;
    Rate(const Rate &rate) = default;
    Rate &operator=(const Rate &rate) = default;
    Rate(Rate &&rate) = default;
    Rate &operator=(Rate &&rate) = default;

    void setBid(const Amount &bid);
    Amount getBid() const;
    void setAsk(const Amount &ask);
    Amount getAsk() const;
};

#endif