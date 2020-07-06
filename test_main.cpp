#define BOOST_TEST_MODULE tests

#include <boost/test/unit_test.hpp>
#include "matrix.h"

BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(case1)
{
    Matrix<int> mat;
    BOOST_CHECK_EQUAL(mat.size(), 0);
    BOOST_CHECK_EQUAL(mat(1,1), -1);
    BOOST_CHECK_EQUAL(mat[1][1], -1);

    mat[1][1] = 5;
    auto val = mat[1][1];
    BOOST_CHECK_EQUAL(val, 5);

    mat[2][2] = 10;
    BOOST_CHECK_EQUAL(mat[2][2], 10);

    auto it = mat.begin();
    while(it != mat.end())
    {
        BOOST_CHECK(it->second != -1);
        ++it;
    }
}

BOOST_AUTO_TEST_SUITE_END()