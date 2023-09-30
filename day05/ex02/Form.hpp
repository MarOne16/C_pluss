#if !defined(FORM_HPP)
#define FORM_HPP


#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

class Bureaucrat;

class AForm
{
    public:
    virtual ~AForm() {}
    virtual void execute(const Bureaucrat &executor) const = 0;
    virtual const std::string &getName(void) const = 0;
    virtual bool getIsSigned(void) const = 0;
    virtual int getGradeToSign(void) const = 0;
    virtual int getGradeToExecute(void) const = 0;
    virtual void beSigned(const Bureaucrat &br) = 0;
};


class Form
{
    private:
    const std::string name;
    bool        isSigned;
    const int   gradeToSign;
    const int   gradeToExecute;
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
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &fr);
    ~Form();
    Form& operator=(const Form &fr);
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat &br);
};

std::ostream& operator<<(std::ostream& os, const Form& fr);
#include "Bureaucrat.hpp"

#endif // Form_HPP
