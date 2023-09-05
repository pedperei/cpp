#pragma once

#include <iostream>

class Fixed
{
private:
    int rawBits;
    static const int fractBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& copy);
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int getFractBits(void) const;
};

