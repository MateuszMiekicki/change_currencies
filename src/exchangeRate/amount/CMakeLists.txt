cmake_minimum_required(VERSION 3.17)

project(Amount VERSION 1.0.0)

add_library(Amount
    Amount.cc
)
add_library(ExchangeRate::Amount ALIAS Amount)

target_include_directories(Amount
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
set_target_properties(Amount
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)