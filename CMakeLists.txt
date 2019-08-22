cmake_minimum_required(VERSION 3.2)

project(IPFilter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(version.h)

add_executable(IPFilter main.cpp)

set_target_properties(IPFilter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(IPFilter
    PRIVATE "${CMAKE_BINARY_DIR}"
)
install(TARGETS IPFilter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include(CPack)
