/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:56:15 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/03 21:18:10 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string A = "HI THIS IS BRAIN";

    std::string *stringPTR = &A;
    std::string &stringREF = A;

    std::cout <<"he memory address of the string variable : "<< &A << std::endl;
    std::cout <<"The memory address held by stringPTR     : "<< stringPTR << std::endl;
    std::cout <<"The memory address held by stringREF     : "<< &stringREF << std::endl;

    std::cout <<"The value of the string variable         : "<< A << std::endl;
    std::cout <<"The value pointed to by stringPTR        : "<< *stringPTR << std::endl;
    std::cout <<"The value pointed to by stringREF        : "<< stringREF << std::endl;
    return (0);
}
