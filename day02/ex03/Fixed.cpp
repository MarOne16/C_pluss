#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const int integer)
{
    value = integer << fractional_bits;
}

Fixed::Fixed(const float floating)
{
    value = static_cast<int>(roundf((floating) * (1 << fractional_bits)));
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
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

}

bool   Fixed::operator<(const Fixed &other)
{
    return(this->value < other.value);
}

bool   Fixed::operator>(const Fixed &other)
{
    return(this->value > other.value);
}

bool   Fixed::operator<=(const Fixed &other)
{
    return(this->value <= other.value);
}

bool   Fixed::operator>=(const Fixed &other)
{
    return(this->value >= other.value);
}

bool   Fixed::operator==(const Fixed &other)
{
    return(this->value == other.value);
}

bool   Fixed::operator!=(const Fixed &other)
{
    return(this->value != other.value);
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->value = other.value;
    }
    return (*this);
}

Fixed   Fixed::operator+(const Fixed &other)
{
    Fixed tmp;
    tmp.setRawBits(this->value + other.value);
    return (tmp);
}

Fixed   Fixed::operator-(const Fixed &other)
{
    Fixed tmp;
    tmp.setRawBits(this->value - other.value);
    return (tmp);
}

Fixed   Fixed::operator*(const Fixed &other)
{
    Fixed tmp;
    long long int total = (static_cast<long long int>(this->value * other.value)) >> (this->fractional_bits); 
    tmp.setRawBits(static_cast<int>(total));
    return (tmp);
}

Fixed       Fixed::operator/(const Fixed &other)
{
    Fixed tmp;
    if (other.value != 0)
    {
        long long int dev = static_cast<long long int>((this->value << this->fractional_bits) / other.value);
        tmp.setRawBits(static_cast<int>(dev));
    }
    else
        tmp.setRawBits(INT_MAX);
    return (tmp);
}

//prefix
Fixed Fixed::operator++(int)
{
    Fixed old;
    old.value = this->value;
    this->value++;
    return(old);
}
Fixed Fixed::operator--(int)
{
    Fixed old;
    old.value = this->value;
    this->value--;
    return(old);
}
//postfix
Fixed   &Fixed::operator++()
{
    this->value++;
    return(*this);
}

Fixed   &Fixed::operator--()
{
    this->value--;
    return(*this);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (((a.value > b.value) ? a : b));
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (((a.value < b.value) ? a : b));
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (((a.value > b.value) ? a : b));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (((a.value < b.value) ? a : b));
}