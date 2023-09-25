/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:32:56 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/24 23:32:46 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
    this->type = cat.type;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*cat.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return (*this);
    this->type = cat.type;
    delete this->brain;
    this->brain = new Brain(*cat.brain);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow meow" << std::endl;
}
