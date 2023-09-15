#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(const Animal &animal);
        Animal();
        virtual ~Animal();
        std::string getType() const;
        Animal &operator=(const Animal &animal);
        virtual void makeSound() const;
};

#endif // ANIMAL_HPP
