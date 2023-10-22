#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <stdexcept>


class RPN
{
    private:
        int result;
        std::string rpn;
        RPN& operator=(const RPN& other);
        RPN(const RPN& other);
        RPN();
    public:
        RPN(std::string &rpn);
        ~RPN();
        void rpnToInfix();
        int getResult() const { return this->result; };
};
bool isOperator(char c);
int strToInt(std::string str);
int getValue(int a, int b, char c);
