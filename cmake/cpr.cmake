FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/whoshuu/cpr.git
)
if(NOT cpr_POPULATED)
    FetchContent_Populate(cpr)
    set(BUILD_SHARED_LIBS ON CACHE INTERNAL "Build SHARED libraries")
    add_subdirectory(${cpr_SOURCE_DIR} ${cpr_BINARY_DIR})
endif()