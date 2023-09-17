#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP

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

#endif // ANIMAL_HPP
