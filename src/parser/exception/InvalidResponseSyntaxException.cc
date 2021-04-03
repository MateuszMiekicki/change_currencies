#include "parser/exception/InvalidResponseSyntaxException.hpp"
#include <string>

const char *InvalidResponseSyntaxException::what() const noexcept
{
    const auto msg = std::string("The format is not implementation compliant. "
                                 "Required fields shown below:") +
                     std::string("[ "
                                 "{ "
                                 "\"effectiveDate\": , "
                                 "\"rates\": "
                                 "[ "
                                 "{ \"code\": , \"bid\": , \"ask\": }, "
                                 "{ \"code\": , \"bid\": , \"ask\": }, "
                                 "{ \"code\": , \"bid\": , \"ask\": }, "
                                 "{ \"code\": , \"bid\": , \"ask\": } "
                                 "] "
                                 "} "
                                 "]\n");
    return msg.c_str();
}