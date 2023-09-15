#if !defined(WRONGANIMAL_HPP)
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif // WRONGANIMAL_HPP
