#if !defined(PRESIDENTIALPARDONFORM_HPP)
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    const std::string target;
    public:
    void execute(const Bureaucrat &executor) const;
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat &br);
    PresidentialPardonForm(const std::string &target);
}

#endif // 
