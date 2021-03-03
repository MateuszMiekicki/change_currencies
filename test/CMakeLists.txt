cmake_minimum_required(VERSION 3.17)

project(change_currencies_test VERSION 1.0.0)

include(FetchContent)
include(cmake/googletest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(change_currencies_test
    main.cc
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
)

if(MSVC)
    #ToDo: add flags for msfc
else()
    target_compile_options(change_currencies_test
            PRIVATE
            -O3 -g3 -Wall -Wextra -pedantic
        )
endif()