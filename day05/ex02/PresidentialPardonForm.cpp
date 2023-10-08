#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
    std::cout << "PresidentialPardonForm constractor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constractor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf)
{
    std::cout << "PresidentialPardonForm copy constractor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    static_cast<std::string>(this->target) = static_cast<std::string>(ppf.target )
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    else
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox\n";
}

const std::string &PresidentialPardonForm::getName(void) const
{
    return (this->AForm::getName());
}

bool PresidentialPardonForm::getIsSigned(void) const
{
    return (this->AForm::getIsSigned());
}

int PresidentialPardonForm::getGradeToSign(void) const
{
    return (this->AForm::getGradeToSign());
}

int PresidentialPardonForm::getGradeToExecute(void) const
{
    return (this->AForm::getGradeToExecute());
}

void PresidentialPardonForm::beSigned(const Bureaucrat &br)
{
    this->AForm::beSigned(br);
}

