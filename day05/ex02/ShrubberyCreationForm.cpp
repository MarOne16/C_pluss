#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    static_cast<std::string>(this->target) = (scf.target);
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::ofstream ofs(this->target + "_shrubbery");
        ofs << "          .     .  .      +     .      .          .\n";
        ofs << "     .       .      .     #       .           .\n";
        ofs << "        .      .         ###            .      .      .\n";
        ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
        ofs << "          .      . \"####\"###\"####\"  .\n";
        ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
        ofs << "  .             \"#########\"#########\"        .        .\n";
        ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
        ofs << "     .     .  \"#######\"##\"####\"##\"#######\"                  .\n";
        ofs << "                .\"##\"#####\"#####\"##\"           .      .\n";
        ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
        ofs << "      .     \"#######\"##\"####\"##\"#######\"      .     .\n";
        ofs << "    .    .     \"#####\"\"#######\"\"####\"    .      .\n";
        ofs << "            .     \"      000      \"    .     .\n";
        ofs << "       .         .   .   000     .        .       .\n";
        ofs << ".. .. ..................O000O........................ ......";
    ofs.close();
}

const std::string &ShrubberyCreationForm::getName(void) const
{
    return (this->name);
}

bool ShrubberyCreationForm::getIsSigned(void) const
{
    return (this->isSigned);
}

int ShrubberyCreationForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int ShrubberyCreationForm::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &br)
{
    AForm::beSigned(br);
}
