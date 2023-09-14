#if !defined(CLAPTRAP_HPP)
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string Name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;

public:
    // Constructors and Destructor
    ClapTrap(std::string name);
    ClapTrap(int hitPoints, int energyPoints, int attackDamage);
    ClapTrap(const ClapTrap &other);
    ClapTrap();
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
