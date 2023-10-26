#include "RPN.hpp"

int main(int argc,const char** argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Usage: ./rpn \"rpn expression\"");
        RPN rpn(argv);
        rpn.rpnToInfix();
        rpn.showResult();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}