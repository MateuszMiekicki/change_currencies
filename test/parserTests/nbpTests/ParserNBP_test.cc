#include "date/date.h"
#include "parser/Parser.hpp"
#include "parser/exception/InvalidResponseSyntaxException.hpp"
#include "parser/nbp/ParserNBP.hpp"
#include "gtest/gtest.h"
#include <memory>
#include <string>

#include <iostream>

namespace
{
    namespace JSON
    {
        const std::string VALID{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
        const std::string STRUCTURE_IS_AN_OBJECT_INSTEAD_OF_AN_ARRAY{"{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}"};
        const std::string MINIMUM_CORRECT_VERSION{"[ { \"effectiveDate\": \"2021-03-19\", \"rates\": [ { \"currency\": \"dolar dolar amerykański\", \"code\": \"USD\", \"bid\": 3.8401, \"ask\": 3.9177 }, { \"currency\": \"dolar australijski\", \"code\": \"AUD\", \"bid\": 2.9879, \"ask\": 3.0483 }, { \"currency\": \"dolar kanadyjski\", \"code\": \"CAD\", \"bid\": 3.0852, \"ask\": 3.1476 }, { \"currency\": \"euro\", \"code\": \"EUR\", \"bid\": 4.5774, \"ask\": 4.6698 }, { \"currency\": \"forint (Węgry)\", \"code\": \"HUF\", \"bid\": 0.012413, \"ask\": 0.012663 }, { \"currency\": \"frank szwajcarski\", \"code\": \"CHF\", \"bid\": 4.1322, \"ask\": 4.2156 }, { \"currency\": \"funt szterling\", \"code\": \"GBP\", \"bid\": 5.3499, \"ask\": 5.4579 }, { \"currency\": \"jen (Japonia)\", \"code\": \"JPY\", \"bid\": 0.035214, \"ask\": 0.035926 }, { \"currency\": \"korona czeska\", \"code\": \"CZK\", \"bid\": 0.1748, \"ask\": 0.1784 }, { \"currency\": \"korona duńska\", \"code\": \"DKK\", \"bid\": 0.6156, \"ask\": 0.6280 }, { \"currency\": \"korona norweska\", \"code\": \"NOK\", \"bid\": 0.4534, \"ask\": 0.4626 }, { \"currency\": \"korona szwedzka\", \"code\": \"SEK\", \"bid\": 0.4510, \"ask\": 0.4602 }, { \"currency\": \"SDR (MFW)\", \"code\": \"XDR\", \"bid\": 5.4865, \"ask\": 5.5973 } ] } ]"};
        namespace EFFECTIVE_DATE
        {
            const std::string TYPO_IN_FIELD_NAME{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"efectiveDate\":\"2021-03-10\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
            const std::string FIELD_IS_MISSING{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
        }
        namespace RATES
        {
            const std::string TYPO_IN_FIELD_NAME{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\",\"rate\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
            const std::string FIELD_IS_MISSING{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\"}]"};
            const std::string TYPO_IN_INTERNAL_BID_FIELD{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500,\"ask\":0.4590},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bidd\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
            const std::string FIELD_IS_MISSING_IN_INTERNAL_ASK_FIELD{"[{\"table\":\"C\",\"no\":\"047/C/NBP/2021\",\"tradingDate\":\"2021-03-09\",\"effectiveDate\":\"2021-03-10\",\"rates\":[{\"currency\":\"dolar amerykański\",\"code\":\"USD\",\"bid\":3.8113,\"ask\":3.8883},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"bid\":2.9361,\"ask\":2.9955},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"bid\":3.0192,\"ask\":3.0802},{\"currency\":\"euro\",\"code\":\"EUR\",\"bid\":4.5356,\"ask\":4.6272},{\"currency\":\"forint (Węgry)\",\"code\":\"HUF\",\"bid\":0.012369,\"ask\":0.012619},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"bid\":4.0981,\"ask\":4.1809},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"bid\":5.3026,\"ask\":5.4098},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"bid\":0.035073,\"ask\":0.035781},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"bid\":0.1728,\"ask\":0.1762},{\"currency\":\"korona duńska\",\"code\":\"DKK\",\"bid\":0.6098,\"ask\":0.6222},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"bid\":0.4500},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"bid\":0.4474,\"ask\":0.4564},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"bid\":5.4485,\"ask\":5.5585}]}]"};
        }
    }
}

TEST(ParserNBP, whenGiveCorrectJsonToParseShouldNotThrowAnException)
{
    ParserNBP nbp;
    ASSERT_NO_THROW(nbp.parse(JSON::VALID));
}

TEST(ParserNBP, whenGiveMinimumCorrectJsonToParseShouldNotThrowAnException)
{
    ParserNBP nbp;
    ASSERT_NO_THROW(nbp.parse(JSON::MINIMUM_CORRECT_VERSION));
}
#include <iostream>

TEST(ParserNBP,
     whenGiveMinimumCorrectJsonToParseShouldNotThrowAnExceptionAndShouldBeAvailableToRates)
{
    ParserNBP nbp;
    ASSERT_NO_THROW(nbp.parse(JSON::MINIMUM_CORRECT_VERSION));
    ASSERT_EQ(nbp.getResult().at("USD").getBid(), 3.8401);
}

TEST(ParserNBP,
     whenGiveMinimumCorrectJsonToParseShouldNotThrowAnExceptionAndShouldBeAvailableToEffectiveDate)
{
    ParserNBP nbp;
    ASSERT_NO_THROW(nbp.parse(JSON::MINIMUM_CORRECT_VERSION));
    using namespace date::literals;
    ASSERT_EQ(nbp.getEffectiveDate(), date::year_month_day{2021_y / mar / 19});
}

TEST(ParserNBP,
     whenGiveJsonToParseWhenStructureIsAnObjectInsteadOfAnArrayShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::STRUCTURE_IS_AN_OBJECT_INSTEAD_OF_AN_ARRAY),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP,
     whenGiveJsonToParseWhenEffectiveDateFieldIsMissingShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::EFFECTIVE_DATE::FIELD_IS_MISSING),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP,
     whenGiveJsonToParseWhenTypoInEffectiveDateFieldNameShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::EFFECTIVE_DATE::TYPO_IN_FIELD_NAME),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP, whenGiveJsonToParseWhenRatesFieldIsMissingShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::RATES::FIELD_IS_MISSING),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP, whenGiveJsonToParseWhenTypoInRatesFieldNameShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::RATES::TYPO_IN_FIELD_NAME),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP, whenGiveJsonToParseWhenTypoInInternalBidFieldShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::RATES::TYPO_IN_INTERNAL_BID_FIELD),
                 InvalidResponseSyntaxException);
}

TEST(ParserNBP,
     whenGiveJsonToParseWhenFieldIsMissingInInternalAskFieldShouldThrowException)
{
    ParserNBP nbp;
    ASSERT_THROW(nbp.parse(JSON::RATES::FIELD_IS_MISSING_IN_INTERNAL_ASK_FIELD),
                 InvalidResponseSyntaxException);
}
