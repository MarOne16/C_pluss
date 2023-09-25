/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:25:00 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/24 23:36:55 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
    this->type = dog.type;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->type = dog.type;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}


