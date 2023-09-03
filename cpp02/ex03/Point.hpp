#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &p);
        Point &operator=(const Point &point);
        ~Point();
        float getXv();
        float getYv();
};
