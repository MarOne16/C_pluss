/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:56:15 by mqaos             #+#    #+#             */
/*   Updated: 2023/08/31 22:02:32 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << (stringPTR) << std::endl;
    std::cout << &(stringREF) << std::endl;

    std::cout << (stringPTR) << std::endl;
    std::cout << &(stringREF) << std::endl;
    return (0);
}
