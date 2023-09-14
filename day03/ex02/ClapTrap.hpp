/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:43:03 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/14 22:07:03 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    ClapTrap(std::string name);
    ClapTrap(int hitPoints, int energyPoints, int attackDamage);
    ClapTrap(const ClapTrap &other);
    ClapTrap();
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &other);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP