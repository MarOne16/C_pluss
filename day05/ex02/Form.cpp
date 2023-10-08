#include "Form.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "AForm default constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &af) : name(af.name), isSigned(af.isSigned), gradeToSign(af.gradeToSign), gradeToExecute(af.gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &af)
{
    std::cout << "AForm operator= called" << std::endl;
    this->isSigned = af.isSigned;
    return (*this);
}

void AForm::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}

const std::string &AForm::getName(void) const
{
    return (this->name);
}

bool AForm::getIsSigned(void) const
{
    return (this->isSigned);
}

int AForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw() 
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() 
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& af)
{
    os << "Form name: " << af.getName() << std::endl;
    os << "Form is signed: " << af.getIsSigned() << std::endl;
    os << "Form grade to sign: " << af.getGradeToSign() << std::endl;
    os << "Form grade to execute: " << af.getGradeToExecute() << std::endl;
    return (os);
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    else if (!this->isSigned)
        throw AForm::FormNotSignedException();
}



