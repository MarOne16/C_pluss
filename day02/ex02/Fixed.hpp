#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
	int value;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(const int integer);
	Fixed(const float floating);
	Fixed(const Fixed &other) : value(other.value) {}
	~Fixed();
	// Member functions
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
	// arithmetic operators:
	Fixed   operator+(const Fixed &other);
	Fixed   operator-(const Fixed &other);
	Fixed   operator*(const Fixed &other);
	Fixed   operator/(const Fixed &other);
	Fixed   &operator=(const Fixed &other);
	// comparison operators: 
	bool    operator<(const Fixed &other);
	bool    operator>(const Fixed &other);
	bool    operator<=(const Fixed &other);
	bool    operator>=(const Fixed &other);
	bool    operator==(const Fixed &other);
	bool    operator!=(const Fixed &other);
	// increment/decrement
	//postfix
	Fixed	&operator++();
	Fixed	&operator--();
	//prefix
	Fixed	operator++(int);
	Fixed	operator--(int);
	//verloaded member functions
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static  Fixed &max( Fixed &a,  Fixed &b);
	static  Fixed &min( Fixed &a,  Fixed &b);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
