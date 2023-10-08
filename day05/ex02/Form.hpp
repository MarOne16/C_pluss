#if !defined(FORM_HPP)
#define FORM_HPP


#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

class Bureaucrat;

class AForm
{
    protected:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    AForm();
    public:
    class GradeTooHighException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &af);
    virtual ~AForm();
    AForm& operator=(const AForm &af);
    void beSigned(const Bureaucrat &br);
    virtual void execute(const Bureaucrat &executor) const = 0;
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
};



#include "Bureaucrat.hpp"

#endif // Form_HPP
