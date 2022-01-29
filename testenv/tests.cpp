// 
// @rajeevp
//

#include <iostream>
#include <Eigen/Dense>
#include <boost/math/constants/constants.hpp>
#include <gtest/gtest.h>

#include "utils.hpp"

int test_eigen()
{
    std::cout << "Eigen Demo " << std::endl;
    Eigen::Matrix<float,8,1> v0;
    v0(0,0) = boost::math::constants::pi<float>();
    v0(1,0) = boost::math::constants::pi<float>()*2.0f;

    std::cout << " v0: " << v0 << std::endl;

    Eigen::Matrix3f A;
    A << 1,2,3, 4,5,6, 7,8,9;

    Eigen::Vector3f b;
    b << 3, 3, 4;

    std::cout << "Matrix A: " << A << std::endl;
    std::cout << "Matrix b: " << b << std::endl;

    Eigen::Vector3f x= A.colPivHouseholderQr().solve(b);
    std::cout << "Solution of Ax = b is : x= " << x << std::endl;
    return 1;
}

TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("Hello", "World");
    EXPECT_EQ(7*6.0, 42.0);
}


TEST(UtilsTests, ComputeTest)
{
    EXPECT_FLOAT_EQ( (boost::math::constants::pi<float>()*4.3)+1.1, 
                compute(boost::math::constants::pi<float>(), 1.1));
}


TEST(UtilsTests, SumTest)
{
    EXPECT_EQ( 4+3, sum(4,3) );
}


TEST(EigenTests, MockTest)
{
    EXPECT_EQ( 1, test_eigen() );
}