/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:33:02 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 21:31:10 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(WEAPON_HPP)
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		const std::string	&getType();
		void		setType(std::string Type);
		Weapon(std::string Type);
		~Weapon(void);
};


#endif
