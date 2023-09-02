/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:54:54 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/31 16:19:17 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int nemberZ;
    int i;

    nemberZ = 10;
    i = -1;
    Zombie *zmb = zombieHorde(10 , "maro");
    while (++i < 10)
        zmb[i].announce();
    delete[] zmb;
    return 0;
}
