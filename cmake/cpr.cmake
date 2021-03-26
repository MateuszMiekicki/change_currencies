FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/whoshuu/cpr.git
    GIT_TAG 1.6.0
)
if(NOT cpr_POPULATED)
    FetchContent_Populate(cpr)
    set(BUILD_SHARED_LIBS ON CACHE INTERNAL "Build SHARED libraries")
    if(WIN32)
        set(CPR_FORCE_OPENSSL_BACKEND ON CACHE INTERNAL "With OpenSSL")
    endif()
    add_subdirectory(${cpr_SOURCE_DIR} ${cpr_BINARY_DIR})
endif()