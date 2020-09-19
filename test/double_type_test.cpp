#include <gtest/gtest.h>
#include <solution.h>

TEST(test_double, plus_zero) {
    double a = +0;
    ASSERT_TRUE(checkForPlusZero(convertToUint64(a)));
}

TEST(test_double, minus_zero) {
    double a = -0.0;
    ASSERT_TRUE(checkForMinusZero(convertToUint64(a)));
}

TEST(test_double, plus_inf) {
    double a = std::numeric_limits<double>::infinity();
    ASSERT_TRUE(checkForPlusInf(convertToUint64(a)));
}

TEST(test_double, minus_inf) {
    double a = -std::numeric_limits<double>::infinity();
    ASSERT_TRUE(checkForMinusInf(convertToUint64(a)));
}

TEST(test_double, plus_norm) {
    double a = std::numeric_limits<double>::max();
    ASSERT_TRUE(checkForPlusNormal(convertToUint64(a)));
    a = std::numeric_limits<double>::min();
    ASSERT_TRUE(checkForPlusNormal(convertToUint64(a)));
}

TEST(test_double, minus_norm) {
    double a = -std::numeric_limits<double>::max();
    ASSERT_TRUE(checkForMinusNormal(convertToUint64(a)));
    a = -std::numeric_limits<double>::min();
    ASSERT_TRUE(checkForMinusNormal(convertToUint64(a)));
}

TEST(test_double, plus_denorm) {
    double a = std::numeric_limits<double>::denorm_min();
    ASSERT_TRUE(checkForPlusDenormal(convertToUint64(a)));
}

TEST(test_double, minus_denorm) {
    double a = -std::numeric_limits<double>::denorm_min();
    ASSERT_TRUE(checkForMinusDenormal(convertToUint64(a)));
}

TEST(test_double, qnan) {
    double a = std::numeric_limits<double>::quiet_NaN();
    ASSERT_TRUE(checkForQuietNan(convertToUint64(a)));
    a = -std::numeric_limits<double>::quiet_NaN();
    ASSERT_TRUE(checkForQuietNan(convertToUint64(a)));
}

TEST(test_double, snan) {
    double a = std::numeric_limits<double>::signaling_NaN();
    ASSERT_TRUE(checkForSignalingNan(convertToUint64(a)));
    a = -std::numeric_limits<double>::signaling_NaN();
    ASSERT_TRUE(checkForSignalingNan(convertToUint64(a)));
}