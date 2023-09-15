/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:56:11 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/15 19:58:30 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(const WrongCat &wrongCat)
{
    *this = wrongCat;
}

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    this->type = wrongCat.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound!" << std::endl;
}