#include "Span.hpp"

Span::Span(int n)
{
    if (n < 0)
        throw Span::unsignedInt();
    this->N = n;
}

Span::~Span()
{
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->N = copy.N;
        this->Darray = copy.Darray;
    }
    return (*this);
}
void Span::addNumber(int n)
{
    if (std::find(this->Darray.begin(), this->Darray.end(), n) != this->Darray.end())
        throw Span::alreadyExist();
    if (static_cast<int>(this->Darray.size()) >= this->N)
        throw Span::smallArray();
    this->Darray.push_back(n);
}


unsigned int Span::shortestSpan(void)
{
    if (this->Darray.size() < 2)
        throw Span::addMorenumber();
    int shortest = INT_MAX;
    std::vector<int>::iterator it = this->Darray.begin();
    std::vector<int>::iterator ite = this->Darray.end();
    while (it != ite)
    {
        if (it + 1 != ite)
        {
            if (shortest > *(it + 1) - *it)
                shortest = fabs(*(it + 1) - *it);
        }
        it++;
    }
    return (shortest);
}

unsigned int Span::longestSpan(void)
{
    if (this->Darray.size() < 2)
        throw Span::unsignedInt();
    int longest = INT_MIN;
    std::vector<int>::iterator it = this->Darray.begin();
    std::vector<int>::iterator ite = this->Darray.end();
    while (it != ite)
    {
        if (it + 1 != ite)
        {
            if (longest < *(it + 1) - *it)
                longest = fabs(*(it + 1) - *it);
        }
        it++;
    }
    return (longest);
}