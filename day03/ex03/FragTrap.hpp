#if !defined(FRAGTRAP_HPP)
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:

    FragTrap(std::string name);
    FragTrap();
    FragTrap(const FragTrap &other);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &other);
    virtual void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif // FragTrap
