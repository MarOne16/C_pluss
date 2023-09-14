/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:47:46 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/15 00:12:46 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called for " << name << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called for " << Name << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
    if (this != &other)
    {
        *this = other;
    }
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " is destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << Name << " requests a high-five!" << std::endl;
} 

void FragTrap::attack(const std::string& target)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " can't attack, not enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    HitPoints--;
}