#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

class Bureaucrat
{
    private:
    int grade;
    const std::string name;
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
    Bureaucrat(int Grade,const std::string &name);
    ~Bureaucrat();
    void incrementGrade(void);
    void decrementGrade(void);
    const std::string &getName(void) const;
    int getGrade(void) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif // BUREAUCRAT_HPP
