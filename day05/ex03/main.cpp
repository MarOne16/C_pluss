
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery", "Bender");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}