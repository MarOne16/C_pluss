/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:43:40 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/31 16:26:38 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
void Zombie::set_name(std::string Name)
{
    name = Name;
}
Zombie  *zombieHorde( int N, std::string name )
{
    if(N <= 0)
        return(NULL);
    Zombie *zmb = new Zombie[N];
    int i;

    i = -1;
    while(++i < N)
        zmb[i].set_name(name);
    return (zmb);
}