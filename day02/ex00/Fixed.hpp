/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:55:43 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/11 19:14:52 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FIXED__HPP)
#define FIXED__HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int value;
	static const int v_b_8 = 8;
public:
	Fixed();
	Fixed(int value) : value(value) {}
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits(int const raw);
};




#endif // FIXED__HPP
