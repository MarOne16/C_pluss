#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1(1, "b1");
        Bureaucrat b2(0, "b1");
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        // b1.incrementGrade();
        // std::cout << b1 << std::endl;
        // b1.decrementGrade();
        // std::cout << b1 << std::endl;
        // b1.decrementGrade();
        // std::cout << b1 << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
