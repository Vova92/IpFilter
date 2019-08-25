cmake_minimum_required(VERSION 3.2)

project(IPFilter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(IPFilter_cli main.cpp)
add_library(IPFilter lib.cpp)
add_executable(test_IP test_IP.cpp)

set_target_properties(IPFilter_cli IPFilter test_IP PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(IPFilter
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_IP PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
target_link_libraries(IPFilter_cli PRIVATE
IPFilter
)
target_link_libraries(test_IP
${Boost_LIBRARIES}
IPFilter
)

install(TARGETS IPFilter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vova.tat22@gmail.com)

include(CPack)

enable_testing()

add_test(test_IP test_IP)
