#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/kgms/unit.hpp"

TEST(TestQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}