/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:36:09 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/14 22:02:04 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Wizard");
    
    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("Enemy2");
    clap.beRepaired(5);
    clap.attack("Enemy3");

    return 0;
}