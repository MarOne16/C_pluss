#if !defined(ARRAY_HPP)
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
    class IndexOutOfRangeException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return "Index out of range";
            }
    };
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);
    T &operator[](unsigned int i);
    unsigned int size() const;
    const T* getArray() const
    {
        return _array;
    }
};


#endif // ARRAY_HPP
