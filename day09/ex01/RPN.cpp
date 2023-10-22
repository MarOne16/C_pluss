#include "RPN.hpp"

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
        return a / b;
    return 0;
}


RPN::RPN(std::string &rpn)
{
    for (size_t i = 0; i < rpn.length(); i++)
    {
        if (isdigit(rpn[i]) || isOperator(rpn[i]))
            rpn.insert(i + 1, " ");
    }
    this->rpn = rpn;
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
            stack.push(strToInt(element));
        else
            throw std::runtime_error("Error in RPN operation");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error in RPN operation");
    this->result = stack.top();
}
