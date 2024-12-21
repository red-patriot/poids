# POIDS

Poids is a physical quantities and units library for C++17.

## Usage

### Getting Started

Basic functionality from poids can be accessed with a single header. This header
provides units in mass, length, and time. The library provides convenient types 
to create physical quantites with units, which looks similar to how the 
quantities would be written out by hand. The library checks and enforces units 
at compile-time.

``` C++
#include <iostream>

#include "poids/kgms.hpp"

using namespace kgms::base; // For base units

int main() {
    kgms::Velocity speed = 3 * meter / second;
    kgms::Time duration = 4 * second;

    kgms::Length distance = speed * duration;   // Units are checked at compile-time

    std::cout << "Travelled " << distance.as(milli(meter)) << " mm"; // Travelled 12000.000 mm 

    return 0;
}

```

Quantities internally know their units and can perform unit conversions with the `as` member function, which returns a double of the quantity in the given units. 

### Concepts

Poids is built on top of the `Quantity`, which is a combination of a `Scalar` 
and `Unit`. The `Scalar` is the underlying value type, such as `double`. The 
`Unit` is a compile-time value carrying unit information, and units are not 
carried over to runtime, giving quantities very little overhead compared to just 
using the `Scalar` directly, while providing the benefit of checking units
 automatically. 

Quantities are extensible in both `Scalar` and `Unit`, and it is possible to 
write a custom version of each if those provided in the library are not
sufficient.

One important concept is the distinction between quantities and base quantities.
Base quantities are the only quantities which can be used as the target for unit
conversions. Most operations on base quantities will produce a non-base quantity,
this is to require users to be explicit about unit conversions. In order to 
explicitly make a base quantity, use `poids::makeBase`.

```C++

kgms::Length value = /* ... */;
kgms::Length notABase = kgms::base::meter * 7;
auto aBase = poids::makeBase<kgms::Length>(7.0); // explicitly create a base

double rawValue1 = value.as(notABase); //! ERROR, does not compile
double rawValue2 = value.as(aBase); 
```

### Other Scalars

Out-of-the-box, poids supports scalar types `double`, `std::complex<double>` and
`Eigen::Vector<double, N>`. 

It is possible to use any arithmetic type as the scalar type for a quantity. The
only requirements put on scalar types are the operations which are used in code, however it is recommended that at least the basic arithmetic operators +,-,*,/
are supported for custom scalar types.

Poids uses a mixin system for custom scalar types so that additional operations
on quantities can be implemented on custom scalars (e.g. the `real` member
on quantities of `std::complex<double>` to access the real part of the quantity).
Poids uses the CRTP class `poids::scalar::ScalarMixin`, which can be specialized 
to provide additional operations. Poids will instantiate this class with two 
template types: the first is the actual concrete `Quantity` type, and the second
is the concrete `Scalar` type.

``` C++
// Snippet of mixin functionality of std::complex<double>:
#include "poids/core/scalar_support.hpp" 

namespace poids::scalar {
  template<typename Derived,
           typename T>
  class ScalarMixin<Derived, std::complex<T>> {
  /*...*/ 
  };
}
```

Where needed, there are metafunctions defined in `poids/core/traits.hpp` to 
access information about the `Derived` parameter, such as the actual unit type,
or whether it is a base unit.

### Custom Unit Systems

Out of the box, poids provides the KGMS (kilogram, meter, second) unit system,
named so after the base values of the system. However, it is very easy to create
a different system. In order to define a new system, create a new type with the
following layout types:

```C++
template<typename...>
struct CustomUnitType {
    template<typename OtherUnitType>
    using multiply_t = /* Result of multiplying two quantities in this system*/;
    template<typename OtherUnitType>
    using divide_t = /* Result of dividing two quantities in this system*/;
    template<int N, unsigned D>
    using power_t = /* Result of raising a quantity in this system to the (N/D) 
                     * power (i.e. Raising to the Nth power, and taking the 
                     * Dth root)*/;
    /*Optional:*/
    using unitless_t = /* The units which indicate no units (just a scalar) */;
};
```

Unitless quantities are treated slightly specially in poids, and they can be implicitly converted to/from the raw `Scalar`, where quantities with units require explicit conversions, like `as`. 
