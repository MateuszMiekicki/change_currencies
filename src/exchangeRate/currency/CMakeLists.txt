cmake_minimum_required(VERSION 3.17)

project(Currency VERSION 1.0.0)

add_library(Currency
    Currency.cc
)
add_library(ExchangeRate::Currency ALIAS Currency)

target_include_directories(Currency
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
set_target_properties(Currency
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)