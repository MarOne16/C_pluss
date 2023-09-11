#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

    Point point(2, 5);
    std::cout << "result: " << bsp(a, b, c, point) << "\n";

    return 0;
}