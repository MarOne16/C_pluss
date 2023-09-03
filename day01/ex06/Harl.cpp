/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:55:18 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:00:20 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::~Harl(void)
{
	return ;
}
Harl::Harl(void)
{
	return ;
}

void    Harl::log(std::string &messag)
{
	std::cout << messag << std::endl;
}