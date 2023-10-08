#if !defined(ROBOTOMYREQUESTFORM_HPP)
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    const std::string target;
    RobotomyRequestForm();
    public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &rrf);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm &rrf);
    void execute(const Bureaucrat &executor) const;
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat &br);
};

#endif // ROBOTOMYREQUESTFORM_HPP
