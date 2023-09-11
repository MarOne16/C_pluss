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

bool bsp( Point  a, Point  b, Point  c, Point  point)
{
    Fixed denominator = ((b.gety() - c.gety()) * (a.getx() - c.getx()) + (c.getx() - b.getx()) * (a.gety() - c.gety()));

    if (denominator == 0)
        return (false);
    Fixed a_numerator = ((b.gety() - c.gety()) * (point.getx() - c.getx()) + (c.getx() - b.getx()) * (point.gety() - c.gety())) / denominator;
    Fixed b_numerator = ((c.gety() - a.gety()) * (point.getx() - c.getx()) + (a.getx() - c.getx()) * (point.gety() - c.gety())) / denominator; 
    float c_numerator = 1.0f - (a_numerator.toFloat() - b_numerator.toFloat());

    return (a_numerator >= 0 && b_numerator >= 0 && c_numerator >= 0);
}