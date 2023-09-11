#include "Point.hpp"

int main()
{
    Point a(1, 1);
    Point b(3, 3);
    Point c(1, 4);

    Point point(2, 3);
    std::cout << "result: " << bsp(a, b, c, point) << "\n";

    return 0;
}