#ifndef Amount_hpp
#define Amount_hpp

class Amount
{
private:
    double _amount;

public:
    Amount() = default;
    Amount(const double amount);
    Amount(const Amount &amount) = default;
    Amount &operator=(const Amount &amount) = default;
    Amount(Amount &&amount) = default;
    Amount &operator=(Amount &&amount) = default;

    void setAmount(const double amount);
    double getAmount() const;
};

#endif