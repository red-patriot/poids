#include <type_traits>

#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/kgms/eigen_support.hpp"

#define KGMS_EIGEN_VECTOR_TYPE_TEST(UnitType, N)                                                 \
  TEST(TestKGMSEigenSupport, UnitType##Vector) {                                                 \
    EXPECT_TRUE((std::is_same_v<Eigen::Vector<double, N>, kgms::UnitType##Vector<N>::Scalar>));  \
    EXPECT_TRUE((std::is_same_v<kgms::units::UnitType##Unit, kgms::UnitType##Vector<N>::Unit>)); \
  }

KGMS_EIGEN_VECTOR_TYPE_TEST(Unitless, 3)

TEST(TestKGMSEigenSupport, AngleVector) {
  EXPECT_TRUE((std::is_same_v<Eigen::Vector<double, 2>, kgms::AngleVector<2>::Scalar>));
  EXPECT_TRUE((std::is_same_v<kgms::units::UnitlessUnit, kgms::AngleVector<2>::Unit>));
}

KGMS_EIGEN_VECTOR_TYPE_TEST(Mass, 4)
KGMS_EIGEN_VECTOR_TYPE_TEST(Length, 5)
KGMS_EIGEN_VECTOR_TYPE_TEST(Time, 6)

KGMS_EIGEN_VECTOR_TYPE_TEST(Area, 2)
KGMS_EIGEN_VECTOR_TYPE_TEST(Volume, 3)
KGMS_EIGEN_VECTOR_TYPE_TEST(SecondMomentOfArea, 10)

KGMS_EIGEN_VECTOR_TYPE_TEST(Frequency, 2)

KGMS_EIGEN_VECTOR_TYPE_TEST(Velocity, 2)
KGMS_EIGEN_VECTOR_TYPE_TEST(Acceleration, 2)

KGMS_EIGEN_VECTOR_TYPE_TEST(Force, 2)
KGMS_EIGEN_VECTOR_TYPE_TEST(Energy, 7)
KGMS_EIGEN_VECTOR_TYPE_TEST(Power, 9)

#undef KGMS_EIGEN_VECTOR_TYPE_TEST