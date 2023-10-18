#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include <cmath>

class Span
{
    private:
        int N;
        std::vector<int> Darray;
        Span(){};
    public: 
    class alreadyExist : public std::exception 
    {
        const char *what() const throw()
        {
            return ("already exist\n");
        }
    };
    class unsignedInt : public std::exception 
    {
        const char *what() const throw()
        {
            return ("the number is negative\n");
        }
    };
    class addMorenumber : public std::exception 
    {
        const char *what() const throw()
        {
            return ("add more number\n");
        }
    };
    class smallArray : public std::exception 
    {
        const char *what() const throw()
        {
            return ("the array is too small\n");
        }
    };
    Span(int n);
    ~Span();
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    void addNumber(int n);
    template <typename T>
    void addNumber(T begin, T end)
    {
        for (T it = begin; it != end; it++)
        {
            addNumber(*it);
        }
    }
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
};