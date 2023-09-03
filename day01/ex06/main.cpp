/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:20:57 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:00:01 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    Harl harl;
    std::string level = argv[1];
    std::string message_debug = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!";
    std::string message_info = "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::string message_warning = "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.";
    std::string message_error = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.";
    
    if (level == "DEBUG")
    {
        harl.log(message_debug);
        harl.log(message_info);
        harl.log(message_warning);
        harl.log(message_error);
    }
    else if (level == "INFO")
    {
        harl.log(message_info);
        harl.log(message_warning);
        harl.log(message_error);
    }
    else if (level == "WARNING")
    {
        harl.log(message_warning);
        harl.log(message_error);
    }
    else if (level == "ERROR")
    {
        harl.log(message_error);
    }
    else
    {
        std::string message = "[ Probably complaining about insignificant problems ]";
        harl.log(message);
    }
    return 0;
}
