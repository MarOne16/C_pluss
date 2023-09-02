/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:50:43 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 20:37:02 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &humanWeapon)
{
    this->name = Name;
    this->weapon = &humanWeapon;   
}

HumanA::~HumanA()
{

}

void    HumanA::attack(void)
{
    std::cout << "<" << this->name << "> attacks with their <" << this->weapon->getType() << ">" << std::endl;
}

void    HumanA::setWeapon(Weapon &humanWeapon)
{
    this->weapon = &humanWeapon;
}