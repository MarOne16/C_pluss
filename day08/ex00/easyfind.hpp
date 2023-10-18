#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>

class NotFound : public std::exception 
{
    const char* what() const throw()
    {
        return "The integer is not found!\n";
    }
};


template<typename type>
typename type::iterator easyfind(type &Container, int ToFind)
{
    typename type::iterator it;
    for (it = Container.begin(); it != Container.end(); ++it)
        if (*it == ToFind)
            return it;
    throw NotFound();
}
