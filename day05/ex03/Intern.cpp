#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    if (this == &other) {
        return *this;
    }
    return *this;
}

const char *Intern::FormNotFoundException::what() const throw() {
    return ("Form not found");
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    int i = 0;
    std::string const formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    AForm *(Intern::*formFunctions[3])(std::string const &target) = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm
    };
    while (i < 3 && name != formNames[i]) {
        i++;
    }
    if (i == 3) {
        throw FormNotFoundException();
    }
    std::cout << "Intern creates " << name << " form" << std::endl;
    return ((this->*formFunctions[i])(target));
}