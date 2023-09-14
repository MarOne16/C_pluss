/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:14:18 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/15 00:32:34 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)  : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
{
    std::cout << "ClapTrap " << Name << " is born with " << HitPoints << " hit points and " << EnergyPoints << " energy points." << std::endl;
}

ClapTrap::ClapTrap()
{
    std::cout << "Default Constractor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy Constractor called\n";
    if (this != &other)
    {
        Name = other.Name;
    }
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        Name = other.Name;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " is destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't attack, not enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    HitPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't take damage, already defeated!" << std::endl;
        return;
    }
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage and has " << HitPoints << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " can't be repaired, already defeated!" << std::endl;
        return;
    }
    HitPoints += amount;
    std::cout << "ClapTrap " << Name << " is repaired for " << amount << " hit points and now has " << HitPoints << " hit points." << std::endl;
    EnergyPoints--;
}