// Fixed.h (or Fixed.hpp)

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractional_bits = 8;
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float floating);
    ~Fixed();

    // Member functions
    float toFloat() const;
    int toInt() const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
