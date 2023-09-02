/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:12:16 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/30 18:36:07 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie *zmb = newZombie(name);
    zmb->announce();
    delete zmb;
}