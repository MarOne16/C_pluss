#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <list>
#include <stdexcept>


class RPN
{
    private:
        int result;
        std::string rpn;
        std::stack<int> stack;
        RPN& operator=(const RPN& other);
        RPN(const RPN& other);
        RPN();
    public:
        RPN(const char **argv);
        ~RPN();
        void rpnToInfix();
        void showResult() const;
};
bool isOperator(char c);
int strToInt(std::string str);
int getValue(int a, int b, char c);
bool notIn(std::string str, std::string s);
