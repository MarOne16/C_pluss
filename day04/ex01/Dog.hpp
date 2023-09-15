#if !defined(DOG_HPP)
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &dog);
        virtual ~Dog();
        Dog &operator=(const Dog &dog);
        virtual void makeSound() const;
};

#endif // DOG_HPP
