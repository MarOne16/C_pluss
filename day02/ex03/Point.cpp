#include "Point.hpp"

Point::Point(void) : a(0), b(0) {}
Point::Point(const Fixed &avalue, const Fixed &bvalue) : a(avalue), b(bvalue){}
Point::Point(const Point &other) : a(other.a), b(other.b){}
Point::~Point() {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        a = other.a;
        b = other.b;
    }
    return (*this);
}

Fixed Point::getx(void)
{
    return (a);
}

Fixed Point::gety(void)
{
    return (b);
}

Fixed get_ocean_triangle(Point a, Point b, Point c)
{
    Fixed result = (a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety()));
    if (result < 0)
        result = result * -1;
    result = result / 2;
    return (result);
}

bool bsp( Point const  a, Point const b, Point const c, Point const point)
{
    Fixed abc = get_ocean_triangle(a, b, c);
    Fixed abp = get_ocean_triangle(a, b, point);
    Fixed apc = get_ocean_triangle(a, point, c);
    Fixed pbc = get_ocean_triangle(point, b, c);
    if (abp == 0 || apc == 0 || pbc == 0)
        return (false);
    if (abc == (abp + apc + pbc))
        return (true);
    return (false);
}