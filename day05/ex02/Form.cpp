#include "Form.hpp"

Form::Form(const std::string &Name, int GradeToSign, int GradeToExecute)
    : name(Name), gradeToSign(GradeToSign), gradeToExecute(GradeToExecute)
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (GradeToSign > 150 || GradeToExecute > 150)
        throw Form::GradeTooLowException();
    this->isSigned = false;
    std::cout << "the constructor called\n";
}

Form::Form(const Form &fr) : name(fr.name), gradeToSign(fr.gradeToSign), gradeToExecute(fr.gradeToExecute)
{
    isSigned = fr.isSigned;
    std::cout << "the copy constructor called\n";
}

Form::~Form()
{
    std::cout << "the Destractor called\n"; 
}

void Form::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() > this->gradeToSign)
    {
        puts("here");
        throw Form::GradeTooLowException();
    }
    else
        this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() 
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

const std::string &Form::getName(void) const
{
    return (name);
}

bool Form::getIsSigned(void) const
{
    return (isSigned);
}

int Form::getGradeToSign(void) const
{
    return (gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (gradeToExecute);
}

std::ostream& operator<<(std::ostream& os, const Form& fr)
{
    os << "Form name: " << fr.getName() << std::endl;
    os << "Form is signed: " << fr.getIsSigned() << std::endl;
    os << "Form grade to sign: " << fr.getGradeToSign() << std::endl;
    os << "Form grade to execute: " << fr.getGradeToExecute() << std::endl;
    return (os);
}