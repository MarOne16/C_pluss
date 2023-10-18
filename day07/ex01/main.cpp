#include "iter.hpp"

int main()
{
    int tab[] = { 0, 1, 2, 3};
    iter(tab, 4, print<int>);
    return 0;
}