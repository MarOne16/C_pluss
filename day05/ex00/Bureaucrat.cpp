#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(int Grade,const std::string &Name) : name(Name)
{
    if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = Grade;
    std::cout << "the constractor called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "the constractor called\n"; 
}


const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

const std::string &Bureaucrat::getName(void) const
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}


void Bureaucrat::incrementGrade(void)
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << std::endl;
    return os;
}