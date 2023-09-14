#if !defined(SCAVTRAP_HPP)
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:

    ScavTrap(std::string name);
    ScavTrap();
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &other);
    void guardGate();
    virtual void attack(const std::string& target);
};

#endif // ScavTrap
