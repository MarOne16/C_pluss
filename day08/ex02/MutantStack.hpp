#pragma once

#include <stack>
#include <iostream>
#include <algorithm>

template<typename T> 
class MutantStack : public std::stack<int>
{
    private:
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &copy) {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }
        MutantStack(const MutantStack &copy)
        {
            *this = copy;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return std::stack<T>::c.begin();
        }
        iterator end() {
            return std::stack<T>::c.end();
        }
};