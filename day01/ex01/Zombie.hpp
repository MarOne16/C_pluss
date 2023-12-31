/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:58:48 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:09:52 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ZOMBIE_HPP)
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private :
	std::string name;

	public:

	void announce( void );
	void set_name(std::string Name);
	Zombie(void);
	~Zombie(void);
};

Zombie  *zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
