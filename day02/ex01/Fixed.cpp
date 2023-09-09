// Fixed.cpp

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    value = 0;
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    value = integer << fractional_bits;
}

Fixed::Fixed(const float floating)
{
    std::cout << "Float constructor called" << std::endl;
    value = static_cast<int>(roundf((floating) * (1 << fractional_bits)));
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / static_cast<float>(1 << fractional_bits);
}

int Fixed::toInt() const {
    return value >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}