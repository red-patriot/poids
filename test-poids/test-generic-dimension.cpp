#include "gtest/gtest.h"

#include <string>

#include <Unit.h>
#include <metric/SIDimension.h>

/** A test class that represents a valid dimension */
class TestingDimension {
 public:
  const int d1;
  const int d2;

  constexpr TestingDimension(int d1_, int d2_) :
      d1(d1_), d2(d2_) { }
  constexpr ~TestingDimension() = default;

  friend consteval TestingDimension operator-(const TestingDimension& rhs) noexcept {
    return TestingDimension(-rhs.d1, -rhs.d2);
  }
  friend consteval TestingDimension operator+(const TestingDimension& lhs, const TestingDimension& rhs) noexcept {
    return TestingDimension(lhs.d1 + rhs.d1, lhs.d2 + rhs.d2);
  }
  friend consteval TestingDimension operator-(const TestingDimension& lhs, const TestingDimension& rhs) noexcept {
    return TestingDimension(lhs.d1 - rhs.d1, lhs.d2 - rhs.d2);
  }

  friend constexpr bool operator==(const TestingDimension& lhs, const TestingDimension& rhs) noexcept = default;
};

TEST(TestGenericDimension, SIDimensionSatisfiesDimensionConcept) {
  auto isValid = poids::Dimension<poids::metric::Dimension>;
  EXPECT_TRUE(isValid);
}

TEST(TestGenericDimension, NonDimensionDoesNotSatisfyDimensionConcept) {
  auto isValid = poids::Dimension<std::string>;
  EXPECT_FALSE(isValid);
}

TEST(TestGenericDimension, ConstructWithTestingDimension) {
  auto isValid = poids::Dimension<TestingDimension>;
  ASSERT_TRUE(isValid) << "Something went wrong, TestingDimension should satsify poids::Dimension";

  const TestingDimension expected(2, 3);
  poids::Unit<TestingDimension(2, 3)> d1;

  EXPECT_EQ(expected, d1.dimension);
}
