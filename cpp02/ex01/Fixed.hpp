#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int rawBits;
    static const int fractBits = 8;
public:
    Fixed(const int rawBits);
    Fixed(const float rawBits);
    Fixed();
    ~Fixed();
    Fixed(const Fixed& copy);
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int getFractBits(void) const;
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
