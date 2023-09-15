#if !defined(CAT_HPP)
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(const Cat &cat);
        Cat();
        ~Cat();
        Cat &operator=(const Cat &cat);
        void makeSound() const;
};

#endif // CAT_HPP
