#include "lib.h"
#include "main.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_ip_filtrated)

BOOST_AUTO_TEST_CASE(test_ip_reverse)
{
    BOOST_CHECK(IP_filtration_check_result(1));
}

BOOST_AUTO_TEST_CASE(test_ip_one)
{
    BOOST_CHECK(IP_filtration_check_result(2));
}
BOOST_AUTO_TEST_CASE(test_ip_four_sev)
{
    BOOST_CHECK(IP_filtration_check_result(3));
}
BOOST_AUTO_TEST_CASE(test_ip_foursix)
{
    BOOST_CHECK(IP_filtration_check_result(4));
}
BOOST_AUTO_TEST_SUITE_END()
