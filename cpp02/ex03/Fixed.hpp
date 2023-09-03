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
    int operator>(const Fixed &fixed) const;
    int operator<(const Fixed &fixed) const;
    int operator>=(const Fixed &fixed) const;
    int operator<=(const Fixed &fixed) const;
    int operator==(const Fixed &fixed) const;
    int operator!=(const Fixed &fixed) const;
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;
    Fixed operator++(int increment);
    Fixed &operator++(void);
    Fixed operator--(int increment);
    Fixed &operator--(void);


    static const Fixed &min(const Fixed &fixed1,const Fixed &fixed2);
    static Fixed &min(Fixed &fixed1,Fixed &fixed2);
    static const Fixed &max(const Fixed &fixed1,const Fixed &fixed2);
    static Fixed &max(Fixed &fixed1,Fixed &fixed2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
