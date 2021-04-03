cmake_minimum_required(VERSION 3.17)

project(ParserException VERSION 1.0.0)

add_library(ParserException
    InvalidResponseSyntaxException.cc
)
add_library(Parser::Exception ALIAS ParserException)
target_include_directories(ParserException
    PUBLIC
    ${rapidjson_SOURCE_DIR}/include
    ${date_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)
set_target_properties(ParserException
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

