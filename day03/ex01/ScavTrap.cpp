/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:38 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/14 22:06:12 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    if (this != &other)
    {
        *this = other;
    }
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " is destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " can't attack, not enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    HitPoints--;
}