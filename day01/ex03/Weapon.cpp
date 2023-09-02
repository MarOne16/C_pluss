/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:47:12 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 21:31:57 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type)
{
    this->type = Type;
}

Weapon::~Weapon(void)
{

}

const std::string &Weapon::getType(void)
{
    const std::string &Type = this->type;
    return(Type);
}

void    Weapon::setType(std::string Type)
{
    this->type = Type;
}