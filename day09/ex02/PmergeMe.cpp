#include "PmergeMe.hpp"

bool isPositiveInteger(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == 32 || str[i] == 9)
            continue;
        else if (str[i] == '+' && isdigit(str[i + 1]))
            continue;
        else if (!isdigit(str[i]))
            return false;
    }
    return true;
}

PmergeMe::PmergeMe(std::string &arg)
{
    if (!isPositiveInteger(arg))
        throw std::runtime_error("Error: argument is not valid");
    this->arg = arg;
    this->result = "";
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::pushToContainers(std::string &str)
{
    std::stringstream ss(str);
    int num;
    while (ss >> num)
    {
        this->v.push_back(num);
        this->d.push_back(num);
    }
}

void PmergeMe::befforAfter(std::string str) const 
{
    std::cout << str;
    for (std::vector<int>::const_iterator it = this->v.begin(); it != this->v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}