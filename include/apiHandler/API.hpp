#ifndef API_hpp
#define API_hpp

#include "cpr/response.h"
#include "currency/Currency.hpp"
#include "date/date.h"

class API
{
public:
    virtual bool connect() = 0;
    virtual bool update() = 0;
    virtual cpr::Response getResponse() const = 0;
    virtual void setUrl(const std::string &url) = 0;
    virtual std::string getUrl() const = 0;
    virtual void setFromCurrency(const Currency &currency) const = 0;
    virtual Currency getFromCurrency() const = 0;
    virtual void setToCurrency(const Currency &currency) const = 0;
    virtual Currency getToCurrency() const = 0;
    virtual void setDate(date::year_month_day &date) = 0;
    virtual void getDate() const = 0;
    virtual void setDateRange(const date::year_month_day &startDate,
                              const date::year_month_day &endDate) = 0;
    virtual std::pair<date::year_month_day,
                      date::year_month_day>
    getRangeDate() const = 0;
    ~API() {}
};

#endif