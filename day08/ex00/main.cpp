#include "easyfind.hpp"
#include <vector>
int main(void)
{
    try
    {
        std::vector<int> Darray;
        Darray.push_back(1);
        Darray.push_back(2);
        Darray.push_back(13);
        Darray.push_back(4);
        Darray.push_back(15);
        std::vector<int>::iterator it = easyfind(Darray, 15);
        std::cout << *it << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
