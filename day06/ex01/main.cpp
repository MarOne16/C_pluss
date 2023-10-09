#include "Serializer.hpp"

int main()
{
    Serializer serializer;
    Data *data = new Data;
    uintptr_t raw;
    Data *data2;

    data->s1 = "Hello";
    data->number = 42;
    data->s2 = "World";
    raw = serializer.serialize(data);
    data2 = serializer.deserialize(raw);
    std::cout << data2->s1 << std::endl;
    std::cout << data2->number << std::endl;
    std::cout << data2->s2 << std::endl;
    delete data2;
    return (0);
}
