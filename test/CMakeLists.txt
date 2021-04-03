cmake_minimum_required(VERSION 3.17)

project(change_currencies_test VERSION 1.0.0)

include(FetchContent)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/googletest.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/parserTests/parserTests.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(change_currencies_test
    main.cc
    ${Parser_tests}
)
set_target_properties(change_currencies_test
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
target_link_libraries(change_currencies_test
    PRIVATE
    gtest gtest_main
    ExchangeRate::ExchangeRate
    ExchangeRate::Amount
    ExchangeRate::Currency
    Parser::NBP
)

if(MSVC)
    #ToDo: add flags for msfc
else()
    target_compile_options(change_currencies_test
            PRIVATE
            -O3 -g3 -Wall -Wextra -pedantic
        )
endif()