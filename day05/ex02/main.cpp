
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat Br(1, "Br");
        ShrubberyCreationForm scf("scf");
        RobotomyRequestForm rrf("rrf");
        PresidentialPardonForm ppf("ppf");
        Br.signForm(scf);
        Br.signForm(rrf);
        Br.signForm(ppf);
        Br.executeForm(scf);
        Br.executeForm(rrf);
        Br.executeForm(ppf);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}