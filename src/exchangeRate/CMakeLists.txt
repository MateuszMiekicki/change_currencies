cmake_minimum_required(VERSION 3.17)

project(ExchangeRate VERSION 1.0.0)

add_library(ExchangeRate
    ExchangeRate.cc
    Rate.cc
)
add_library(ExchangeRate::ExchangeRate ALIAS ExchangeRate)

target_include_directories(ExchangeRate
    PUBLIC
    ${rapidjson_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)
set_target_properties(ExchangeRate
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
add_subdirectory(amount)
add_subdirectory(currency)
target_link_libraries(Currency
    PRIVATE
    ExchangeRate::Amount
    ExchangeRate::Currency
)
