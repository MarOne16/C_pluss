#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
        this->inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete this->inventory[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] && this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
    }
    return (nullptr);
}
