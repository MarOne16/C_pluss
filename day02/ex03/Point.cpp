#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}
Point::Point(const Fixed &avalue, const Fixed &bvalue) : x(avalue), y(bvalue){}
Point::Point(const Point &other) : x(other.x), y(other.y){}
Point::~Point() {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        (Fixed)x = other.x;
        (Fixed)y = other.y;
    }
    return (*this);
}

Fixed Point::getx(void)
{
    return (x);
}

Fixed Point::gety(void)
{
    return (y);
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