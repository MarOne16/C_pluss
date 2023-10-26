#include "RPN.hpp"

bool notIn(std::string str, std::string s)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (s.find(str[i]) == std::string::npos)
            return true;
    }
    return false;
}

int strToInt(std::string str)
{
    std::istringstream ss(str);
    int num;
    ss >> num;
    return num;
}

bool isOperator(char c)
{
    return ((c == '-') || (c == '+') || (c == '*') || (c == '/'));
}

int getValue(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    return 0;
}


RPN::RPN(const char **argv)
{

    for (int i = 1; argv[i]; i++)
    {
        if (notIn(argv[i], "0123456789+-*/ "))
            throw std::runtime_error("Error: invalid argument 1");
        for (size_t j = 0; j < strlen(argv[i]); j++)
        {
            if (argv[i][j] == ' ')
                continue;
            this->rpn += argv[i][j];
            this->rpn += " ";
        }
    }
    this->result = 0;
}

RPN::~RPN()
{

}


void RPN::rpnToInfix()
{
    std::stack<int> stack;
    std::istringstream ss(this->rpn);
    std::string element;

    while (ss >> element)
    {
        if (isOperator(element[0]))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error in RPN operation");
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(getValue(b, a, element[0]));
        }
        else if (isdigit(element[0]))
        {
            stack.push(strToInt(element));
        }
        else
            throw std::runtime_error("Error in RPN operation");
    }
    if (stack.size() != 1)
        throw std::runtime_error("The stack is not empty");
    this->stack = stack;
}

void RPN::showResult() const
{
    std::cout << this->stack.top() << std::endl;
}