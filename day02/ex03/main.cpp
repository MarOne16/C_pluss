#include "Point.hpp"

int main(void)
{
    Point a(7, 7);
    Point b(11, 2);
    Point c(2, 2);

    Point point(7, 4);
    std::cout << "result: " << bsp(a, b, c, point) << "\n";

    return 0;
}