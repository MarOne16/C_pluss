/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:10:54 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 20:59:16 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(HARL_HPP)
#define HARL_HPP

#include <string>
#include <iostream>

// enum Loglevel
// {
//    DEBUG,
//    INFO,
//    WARNING,
//    ERROR,
//    UNKNOWN
// };

class Harl
{
    public:
        void log(std::string &message);
        Harl(void);
        ~Harl(void);
};


#endif // HARL_HPP
