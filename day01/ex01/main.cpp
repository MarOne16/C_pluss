/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:54:54 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:09:14 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int nemberZ;
    int i;

    nemberZ = 10;
    i = -1;
    Zombie *zmb = zombieHorde(nemberZ , "maro");
    while (++i < nemberZ)
        zmb[i].announce();
    delete[] zmb;
    return 0;
}
