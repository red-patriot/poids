#ifndef POIDS_METRIC_SI_DIMENSION_H
#define POIDS_METRIC_SI_DIMENSION_H

#include "rational.h"

namespace poids {
  namespace metric {

    class Dimension {
     public:
      const util::Rational time;
      const util::Rational mass;
      const util::Rational length;
      const util::Rational temperature;
      const util::Rational current;
      const util::Rational amount;
      const util::Rational luminosity;

      constexpr ~Dimension() = default;

      friend consteval Dimension Dimensionless();
      friend consteval Dimension TimeD(const util::Rational& time);
      friend consteval Dimension MassD(const util::Rational& mass);
      friend consteval Dimension LengthD(const util::Rational& length);
      friend consteval Dimension TemperatureD(const util::Rational& temperature);
      friend consteval Dimension CurrentD(const util::Rational& current);
      friend consteval Dimension AmountD(const util::Rational& amount);
      friend consteval Dimension LuminosityD(const util::Rational& luminosity);

      friend consteval Dimension operator+(const Dimension& lhs, const Dimension& rhs) noexcept;
      friend consteval Dimension operator-(const Dimension& lhs, const Dimension& rhs) noexcept;
      friend constexpr bool operator==(const Dimension& lhs, const Dimension& rhs) noexcept = default;

      static consteval Dimension add(const Dimension& lhs, const Dimension& rhs) noexcept;
      static consteval Dimension subtract(const Dimension& lhs, const Dimension& rhs) noexcept;

     private:
      constexpr Dimension(util::Rational timeD = util::Rational(0),
                          util::Rational massD = util::Rational(0),
                          util::Rational lengthD = util::Rational(0),
                          util::Rational temperatureD = util::Rational(0),
                          util::Rational currentD = util::Rational(0),
                          util::Rational amountD = util::Rational(0),
                          util::Rational luminosityD = util::Rational(0));
    };

    consteval Dimension Dimension::add(const Dimension& lhs, const Dimension& rhs) noexcept {
      return lhs + rhs;
    }

    consteval Dimension Dimension::subtract(const Dimension& lhs, const Dimension& rhs) noexcept {
      return lhs - rhs;
    }

    constexpr Dimension::Dimension(util::Rational timeD,
                                   util::Rational massD,
                                   util::Rational lengthD,
                                   util::Rational temperatureD,
                                   util::Rational currentD,
                                   util::Rational amountD,
                                   util::Rational luminosityD) :
        time(timeD),
        mass(massD),
        length(lengthD),
        temperature(temperatureD),
        current(currentD),
        amount(amountD),
        luminosity(luminosityD) { }

    consteval Dimension Dimensionless() {
      return Dimension();
    }

    consteval Dimension TimeD(const util::Rational& time) {
      return Dimension(time);
    }
    consteval Dimension MassD(const util::Rational& mass) {
      return Dimension({0}, mass);
    }
    consteval Dimension LengthD(const util::Rational& length) {
      return Dimension({0}, {0}, length);
    }
    consteval Dimension TemperatureD(const util::Rational& temperature) {
      return Dimension({0}, {0}, {0}, temperature);
    }
    consteval Dimension CurrentD(const util::Rational& current) {
      return Dimension({0}, {0}, {0}, {0}, current);
    }
    consteval Dimension AmountD(const util::Rational& amount) {
      return Dimension({0}, {0}, {0}, {0}, {0}, amount);
    }
    consteval Dimension LuminosityD(const util::Rational& luminosity) {
      return Dimension({0}, {0}, {0}, {0}, {0}, {0}, luminosity);
    }

    consteval Dimension operator+(const Dimension& lhs, const Dimension& rhs) noexcept {
      return Dimension(util::Rational::add(lhs.time, rhs.time),
                       util::Rational::add(lhs.mass, rhs.mass),
                       util::Rational::add(lhs.length, rhs.length),
                       util::Rational::add(lhs.temperature, rhs.temperature),
                       util::Rational::add(lhs.current, rhs.current),
                       util::Rational::add(lhs.amount, rhs.amount),
                       util::Rational::add(lhs.luminosity, rhs.luminosity));
    }

    consteval Dimension operator-(const Dimension& lhs, const Dimension& rhs) noexcept {
      return Dimension(util::Rational::subtract(lhs.time, rhs.time),
                       util::Rational::subtract(lhs.mass, rhs.mass),
                       util::Rational::subtract(lhs.length, rhs.length),
                       util::Rational::subtract(lhs.temperature, rhs.temperature),
                       util::Rational::subtract(lhs.current, rhs.current),
                       util::Rational::subtract(lhs.amount, rhs.amount),
                       util::Rational::subtract(lhs.luminosity, rhs.luminosity));
    }
  }  // namespace metric
}  // namespace poids

#endif  // !POIDS_METRIC_DIMENSION_H
