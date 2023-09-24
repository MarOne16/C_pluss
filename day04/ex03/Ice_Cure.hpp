#if !defined(ICE_CURE_HPP)
#define ICE_CURE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice() : AMateria("ice") {}
    virtual ~Ice() {}
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

class Cure : public AMateria
{
    public:
    Cure() : AMateria("cure") {}
    virtual ~Cure() {}
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // ICE_CURE_HPP
