/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:13:30 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/31 15:58:01 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << "I am " << name << "!" << std::endl;       
}

Zombie::Zombie(void)
{
    
}

Zombie::~Zombie(void)
{
    std::cout << "Destroying zombie: " << name << std::endl;
}