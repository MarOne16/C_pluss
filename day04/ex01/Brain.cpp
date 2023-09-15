#include "Brain.hpp"

Brain::Brain()
{
    this->ideas = new std::string[ideasCount];
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
    delete[] this->ideas;
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return (*this);
}

std::string Brain::getIdea(int index) const
{
    return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}