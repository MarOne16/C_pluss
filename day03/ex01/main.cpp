/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:36:09 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/14 00:34:22 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"


int main()
{
    ScavTrap scavTrap("Scavenger");
    scavTrap.attack("shadow");
    scavTrap.guardGate();
    return 0;
}