/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:42:23 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/01 20:31:23 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(HumanA_HPP)
#define HumanA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        void    attack(void);
        void    setWeapon(Weapon &humanWeapon);
        HumanA(std::string Name, Weapon &humanWeapon);
        ~HumanA(void);
};

#endif
