#include "gtest/gtest.h"

#include <Unit.h>

/** A test class that represents a valid dimension */
class TestDimension {
 public:
  const int d1;
  const int d2;

  constexpr TestDimension(int d1_, int d2_) :
      d1(d1_), d2(d2_) { }
  constexpr ~TestDimension() = default;

  friend consteval TestDimension operator+(const TestDimension& lhs, const TestDimension& rhs) noexcept {
    return TestDimension(lhs.d1 + rhs.d1, lhs.d2 + rhs.d2);
  }
  friend consteval TestDimension operator-(const TestDimension& lhs, const TestDimension& rhs) noexcept {
    return TestDimension(lhs.d1 - rhs.d1, lhs.d2 - rhs.d2);
  }

  friend constexpr bool operator==(const TestDimension& lhs, const TestDimension& rhs) noexcept = default;
};

//TEST(TestGenericDimension, Construct) {
//  const TestDimension expected(2, 3);
//  poids::Unit<TestDimension(2, 3)> d1;
//
//  EXPECT_EQ(expected, d1.dimension);
//}
