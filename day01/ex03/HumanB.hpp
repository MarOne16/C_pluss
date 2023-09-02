/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:45:51 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 20:03:15 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(HumanB_HPP)
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        void    attack(void);
        void    setWeapon(Weapon &humanWeapon);
        HumanB(std::string Name, Weapon &humanWeapon);
        ~HumanB(void);
};


#endif // HumanB_HPP