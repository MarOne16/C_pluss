#if !defined(SHRUBBERYCREATIONFORM_HPP)
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    const std::string target;
    public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &scf);
    ~ShrubberyCreationForm();
    void execute(const Bureaucrat &executor) const;
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat &br);
};

#endif // SHRUBBERYCREATIONFORM_HPP
