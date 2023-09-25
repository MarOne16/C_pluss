#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP

#include <iostream>
#include <string>
//Abstract class
class Animal
{
    public:
        Animal();
        Animal(const Animal &copy);
        virtual ~Animal() = 0;
        Animal &operator=(const Animal &copy);
        virtual void makeSound() const = 0;
};


class Dog : public Animal
{
    private:
        std::string type;
    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();
        Dog &operator=(const Dog &copy);
        void makeSound() const;
};

class Cat : public Animal
{
    private:
        std::string type;
    public:
        Cat();
        Cat(const Cat &copy);
        ~Cat();
        Cat &operator=(const Cat &copy);
        void makeSound() const;
};

#endif // ANIMAL_HPP
