/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:01:44 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/14 23:55:36 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // ClapTrap claptrap("CL4P-TP");
    // ScavTrap scavtrap("SC4V-TP");
    // FragTrap fragtrap("FR4G-TP");
    DiamondTrap diamondtrap("DI4M-TP");

    // claptrap.ClapTrap::attack("Enemy");
    // claptrap.ClapTrap::takeDamage(5);
    // claptrap.ClapTrap::beRepaired(3);

    // scavtrap.ClapTrap::attack("Bandit");
    // scavtrap.guardGate();
    // scavtrap.ClapTrap::takeDamage(15);
    // scavtrap.ClapTrap::beRepaired(10);

    // fragtrap.ClapTrap::attack("Boss");
    // fragtrap.highFivesGuys();
    // fragtrap.ClapTrap::takeDamage(20);
    // fragtrap.ClapTrap::beRepaired(15);

    diamondtrap.attack("Dragon");
    diamondtrap.whoAmI();

    return 0;
}
