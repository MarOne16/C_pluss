#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1(100, "b1");
        b1.incrementGrade();
        std::cout << b1 << std::endl;
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
