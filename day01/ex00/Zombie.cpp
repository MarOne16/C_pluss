/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:47:30 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:07:43 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{

    std::cout << name << ": BraiiiiiiinnnzzzZ..."  << std::endl;
        
}

Zombie::Zombie(std::string Name)
{
    name = Name;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroying zombie: " << name << std::endl;
}
