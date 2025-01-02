#include <type_traits>

#include <gtest/gtest.h>

#include "poids/si.hpp"
#include "poids/scalar_support/eigen_vector.hpp"

#define SI_EIGEN_VECTOR_TYPE_TEST(unit_type, N)                                                       \
  TEST(TestKGMSEigenSupport, unit_type##Vector) {                                                     \
    EXPECT_TRUE((std::is_same_v<Eigen::Vector<double, N>, poids::Vector<si::unit_type, N>::Scalar>)); \
    EXPECT_TRUE((std::is_same_v<si::unit_type::Unit, poids::Vector<si::unit_type, N>::Unit>));        \
  }

SI_EIGEN_VECTOR_TYPE_TEST(Unitless, 3)
SI_EIGEN_VECTOR_TYPE_TEST(Angle, 2)

SI_EIGEN_VECTOR_TYPE_TEST(Mass, 4)
SI_EIGEN_VECTOR_TYPE_TEST(Length, 5)
SI_EIGEN_VECTOR_TYPE_TEST(Time, 6)

SI_EIGEN_VECTOR_TYPE_TEST(Area, 2)
SI_EIGEN_VECTOR_TYPE_TEST(Volume, 3)
SI_EIGEN_VECTOR_TYPE_TEST(SecondMomentOfArea, 10)

SI_EIGEN_VECTOR_TYPE_TEST(Frequency, 2)

SI_EIGEN_VECTOR_TYPE_TEST(Velocity, 2)
SI_EIGEN_VECTOR_TYPE_TEST(Acceleration, 2)

SI_EIGEN_VECTOR_TYPE_TEST(Force, 2)
SI_EIGEN_VECTOR_TYPE_TEST(Energy, 7)
SI_EIGEN_VECTOR_TYPE_TEST(Power, 9)

SI_EIGEN_VECTOR_TYPE_TEST(Current, 10)
SI_EIGEN_VECTOR_TYPE_TEST(Resistance, 2)
SI_EIGEN_VECTOR_TYPE_TEST(Capacitance, 5)

#undef SI_EIGEN_VECTOR_TYPE_TEST