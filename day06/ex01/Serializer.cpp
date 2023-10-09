#include "Serializer.hpp"

Serializer::Serializer()
{
    return ;
}

Serializer::Serializer(Data *data) : _data(data)
{
    return ;
}

Serializer::~Serializer()
{
    return ;
}

Serializer::Serializer(Serializer const &other)
{
    *this = other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
    if (this != &other)
    {
        this->_data = other._data;
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw;
    raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *_data = reinterpret_cast<Data *>(raw);
    return (_data);
}