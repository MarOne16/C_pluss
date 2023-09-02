/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:34:35 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/30 22:59:47 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ZOMBIE_HPP)
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

class Zombie
{
    private :
    std::string name;

    public:

    void announce( void );
    Zombie(std::string Nmae);
    ~Zombie(void);
};

Zombie  *newZombie( std::string name);
void    randomChump( std::string name);

#endif // ZOMBIE_HPP
