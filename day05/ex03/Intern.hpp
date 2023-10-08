#if !defined(INTERN_HPP)
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        AForm *makePresidentialPardonForm(std::string const &target);
        AForm *makeRobotomyRequestForm(std::string const &target);
        AForm *makeShrubberyCreationForm(std::string const &target);
    public:
    class FormNotFoundException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    Intern();
    Intern(Intern const &other);
    ~Intern(void);
    Intern &operator=(Intern const &other);
    AForm *makeForm(std::string const &name, std::string const &target);
};

#endif // INTERN_HPP