FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googleTest
    GIT_TAG        release-1.10.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    set(BUILD_SHARED_LIBS ON CACHE INTERNAL "Build SHARED libraries")
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()