export module poid.util.rational;

import <numeric>;
import <stdexcept>;

namespace poid::util {
  export class Rational {
   public:
    constexpr Rational(std::intmax_t num);
    constexpr Rational(std::intmax_t num, std::intmax_t denom);

    constexpr ~Rational() noexcept = default;

    const std::intmax_t numerator_;
    const std::intmax_t denominator_;

    friend bool operator==(const Rational&, const Rational&) = default;

    static Rational negate(const Rational& rhs);
    static Rational add(const Rational& lhs, const Rational& rhs);
    static Rational subtract(const Rational& lhs, const Rational& rhs);
    static Rational multiply(const Rational& lhs, const Rational& rhs);
    static Rational divide(const Rational& lhs, const Rational& rhs);

   private:
    static constexpr std::intmax_t sign(std::intmax_t a);
    static constexpr std::intmax_t absConstexpr(std::intmax_t a);
  };

  constexpr Rational::Rational(std::intmax_t num) :
      numerator_(num),
      denominator_(1) { }

  constexpr Rational::Rational(std::intmax_t num, std::intmax_t denom) :
      numerator_(sign(denom) * num / std::gcd(num, denom)),
      denominator_(absConstexpr(denom) / std::gcd(num, denom)) {
    if (denom == 0) {
      throw std::exception("denominator of poid.Rational cannot be zero");
    }
  }

  constexpr std::intmax_t Rational::sign(std::intmax_t a) {
    return a < 0 ? -1 : 1;
  }
  constexpr std::intmax_t Rational::absConstexpr(std::intmax_t a) {
    return a < 0 ? -a : a;
  }

  Rational Rational::negate(const Rational& rhs) {
    return Rational(-rhs.numerator_, rhs.denominator_);
  }
  Rational Rational::add(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator_ * rhs.denominator_ + rhs.numerator_ * lhs.denominator_,
                    lhs.denominator_ * rhs.denominator_);
  }
  Rational Rational::subtract(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator_ * rhs.denominator_ - rhs.numerator_ * lhs.denominator_,
                    lhs.denominator_ * rhs.denominator_);
  }
  Rational Rational::multiply(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator_ * rhs.numerator_,
                    lhs.denominator_ * rhs.denominator_);
  }
  Rational Rational::divide(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator_ * rhs.denominator_,
                    lhs.denominator_ * rhs.numerator_);
  }
}  // namespace poid::util
