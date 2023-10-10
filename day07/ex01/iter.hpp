#if !defined(ITER_HPP)
#define ITER_HPP

#include <iostream>

template <typename T, typename F> 
void iter(T *array, size_t length, F f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(const T &a) {
    std::cout << a << " ";
}


#endif // ITER_HPP
