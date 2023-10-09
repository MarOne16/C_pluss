#if !defined(SERIALIZER_HPP)
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>


typedef struct Data
{
    std::string s1;
    std::string s2;
    unsigned int number;
} Data;
class Serializer 
{
    private:
        Data *_data;
    public:
        Serializer();
        Serializer(Data *data);
        ~Serializer();
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

};


#endif // SERIALIZER_HPP
