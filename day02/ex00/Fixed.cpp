/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:09:35 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/08 16:56:11 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed   &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		value = other.value;
	std::cout << "Copy assignment operator calle" << std::endl;
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

Fixed::Fixed(const Fixed &other)
{
	value = other.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(void)
{
	value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}