#if !defined(DOG_HPP)
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(const Dog &dog);
        Dog();
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound() const;
};

#endif // DOG_HPP
