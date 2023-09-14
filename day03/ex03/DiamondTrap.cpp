#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    name = "unamed";
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    if (this != &other) {
        *this = other;
    }
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " is destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        name = other.name;
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
    }
    return (*this);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "DiamondTrap " << Name << " can't attack, not enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "DiamondTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    HitPoints--;
}