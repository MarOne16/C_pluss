#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    static_cast<std::string>(this->target) = (rrf.target);
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " robotomization failed" << std::endl;
}

const std::string &RobotomyRequestForm::getName(void) const
{
    return (this->name);
}

bool RobotomyRequestForm::getIsSigned(void) const
{
    return (this->isSigned);
}

int RobotomyRequestForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int RobotomyRequestForm::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

void RobotomyRequestForm::beSigned(const Bureaucrat &br)
{
    AForm::beSigned(br);
}

