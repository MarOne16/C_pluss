/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:18:34 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 20:37:12 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name, Weapon &humanWeapon)
{
    this->name = Name;
    this->weapon = &humanWeapon;   
}

HumanB::~HumanB()
{

}

void    HumanB::attack(void)
{
    std::cout << "<" << this->name << "> attacks with their <" << this->weapon->getType() << ">" << std::endl;
}

void    HumanB::setWeapon(Weapon &humanWeapon)
{
    this->weapon = &humanWeapon;
}