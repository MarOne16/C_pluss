#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap
{
private:
    std::string name;

public:
    DiamondTrap(const std::string& name);
    DiamondTrap();
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &other);
    virtual void    attack(const std::string& target);
    void whoAmI();
};

#endif
