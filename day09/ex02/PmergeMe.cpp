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

PmergeMe::PmergeMe(char const *argv[])
{
    feedargv(argv);
    this->result = "";
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::pushToContainers()
{
    std::stringstream ss(this->arg);
    int num;
    while (ss >> num)
    {
        this->v.push_back(num);
        this->d.push_back(num);
    }
}

void PmergeMe::befforAfter(std::string str, bool type) const 
{
    if (type)
    {
        std::cout << str;
        for (std::vector<int>::const_iterator it = this->v.begin(); it != this->v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    else
    {
        std::cout << str;
        for (std::deque<int>::const_iterator it = this->d_mainChain.begin(); it != this->d_mainChain.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

void PmergeMe::feedargv(char const *argv[])
{
    if (!argv[1])
        throw std::runtime_error("Error: wrong number of arguments");
    for (int i = 1; argv[i]; i++)
    {
        std::string str(argv[i]);
        if (!isPositiveInteger(str))
            throw std::runtime_error("Error: argument is not valid");
        this->arg += str + " ";
    }
}