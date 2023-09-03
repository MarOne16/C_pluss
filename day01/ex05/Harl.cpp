/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:32:48 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 20:12:09 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void    Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::unknown(void)
{
	std::cout << "UNKNOWN" << std::endl;
}

void	Harl::complain(std::string level)
{
    void (Harl::*functionPtr[5])() =
	{
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
		&Harl::unknown
    };
	std::string levelptr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4 &&  levelptr[i] != level; i++);
	(this->*functionPtr[i])();
}