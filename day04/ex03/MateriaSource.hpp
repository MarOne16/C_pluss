#if !defined(MATERIASOURCE_HPP)
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

// class IMateriaSource;
// class AMateria;
class MateriaSource : public IMateriaSource
{
    private:
    AMateria *inventory[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &other);
        MateriaSource &operator=(MateriaSource const &other);
        ~MateriaSource();
        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP