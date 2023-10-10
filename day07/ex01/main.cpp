#include "iter.hpp"


int main()
{
    int tab[5] = {0, 1, 2, 3, 4};
    float tab2[3] = {0.0f, 1.1f, 2.2f};
    iter(tab, 5, print<int>);
    std::cout << std::endl;
    iter(tab2, 3, print<float>);

    return 0;
}
