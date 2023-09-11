#if !defined(POINT_HPP)
#define POINT_HPP

#include"Fixed.hpp"

class Point
{
private:
    Fixed a;
    Fixed b;
public:
    Point(void);
    Point(const Fixed &avalue, const Fixed &bvalue);
    Point(const Point &other);
    ~Point();
    Point &operator=(const Point &other);
    Fixed getx(void);
    Fixed gety(void);
    bool bsp( Point const a, Point const b, Point const c, Point const point);
};



#endif // POINT_HPP
