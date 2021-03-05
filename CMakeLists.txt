cmake_minimum_required(VERSION 3.17)

project(change_currencies VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(FATAL_ERROR "Available build types: Debug and Release.")
endif(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")

option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
    add_subdirectory (test)
    add_test (NAME UnitTest COMMAND test)
    enable_testing()
endif()

include(FetchContent)
include(${CMAKE_SOURCE_DIR}/cmake/cpr.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/date.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(change_currencies_cli
    src/main.cc
)
set_target_properties(change_currencies_cli
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(change_currencies_cli
                PRIVATE
                -O3 -g3 -Wall -Wextra -pedantic
            )
    endif()
else()
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(change_currencies_cli
                PRIVATE
                -O3 -Wall -Wextra -pedantic
            )
    endif()
endif()