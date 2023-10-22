#include "RPN.hpp"

int main(int argc, char** argv)
{
    try
    {
        if (argc != 2)
            throw std::runtime_error("Usage: ./rpn \"rpn expression\"");
        std::string arg = argv[1];
        RPN rpn(arg);
        rpn.rpnToInfix();
        std::cout << rpn.getResult()  << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}