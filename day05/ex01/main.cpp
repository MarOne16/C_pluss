#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat1(8, "Mar1");
        Form Form1("marmini", 3, 3);
        Form1.beSigned(Bureaucrat1);
        Bureaucrat1.signForm(Form1);
        std::cout << Form1 << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

