#include "Point.hpp"

Point::Point():x(0), y(0)
{

}

Point::Point(const float x, const float y):x(x), y(y)
{
    
}

Point::Point(const Point &p):x(p.x), y(p.y)
{

}

Point &Point::operator=(const Point &p)
{
    return ((Point &)p);
}

Point::~Point()
{

}

float Point::getXv()
{
    return (this->x.toFloat());
}

float Point::getYv()
{
    return (this->y.toFloat());
}