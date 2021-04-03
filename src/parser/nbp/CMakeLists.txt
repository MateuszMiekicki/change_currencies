cmake_minimum_required(VERSION 3.17)

project(ParserNBP VERSION 1.0.0)

add_library(ParserNBP
    ParserNBP.cc
)
add_library(Parser::NBP ALIAS ParserNBP)
target_include_directories(ParserNBP
    PUBLIC
    ${rapidjson_SOURCE_DIR}/include
    ${date_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)
set_target_properties(ParserNBP
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
target_link_libraries(ParserNBP
    PRIVATE
    Parser::Exception
    date::date
    ExchangeRate::ExchangeRate
    ExchangeRate::Amount
    ExchangeRate::Currency
)
