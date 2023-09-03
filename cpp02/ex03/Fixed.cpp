#include "Fixed.hpp"

static	float power_2(int exp)
{
	float   res = 0;

	if (exp == 0)
		return (res);
    res = 2;
	while (--exp)
		res = res * 2;
	return (res);
}

Fixed::Fixed()
{
    this->rawBits=0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int rawBits)
{
    this->rawBits = rawBits * power_2(this->fractBits);
}

Fixed::Fixed(const float rawBits)
{
    this->rawBits = roundf(rawBits * power_2(this->fractBits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    
    this->rawBits=fixed.rawBits;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}

int Fixed::getFractBits(void) const
{
    return (this->fractBits);
}

float	Fixed::toFloat(void) const
{
	return (this->rawBits / power_2(this->fractBits));
}

int		Fixed::toInt(void) const
{
	return (this->rawBits / power_2(this->fractBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::operator>(const Fixed &fixed) const
{
    if(this->rawBits > fixed.rawBits)
        return (1);
    return (0);
}

int Fixed::operator<(const Fixed &fixed) const
{
    if(this->rawBits < fixed.rawBits)
        return (1);
    return (0);
}

int Fixed::operator>=(const Fixed &fixed) const
{
    if(this->rawBits >= fixed.rawBits)
        return (1);
    return (0);
}

int Fixed::operator<=(const Fixed &fixed) const
{
    if(this->rawBits <= fixed.rawBits)
        return (1);
    return (0);
}

int Fixed::operator==(const Fixed &fixed) const
{
    if(this->rawBits == fixed.rawBits)
        return (1);
    return (0);
}

int Fixed::operator!=(const Fixed &fixed) const
{
    if(this->rawBits != fixed.rawBits)
        return (1);
    return (0);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed res;

    res.rawBits = this->rawBits + fixed.rawBits;
    return (res);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed res;

    res.rawBits = this->rawBits - fixed.rawBits;
    return (res);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    float multi = this->toFloat() * fixed.toFloat();
    Fixed res(multi);

    return (res);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    float div = this->toFloat() / fixed.toFloat();
    Fixed res(div);

    return (res);
}

Fixed Fixed::operator++(int increment)
{
    Fixed pre(*this);
    (void) increment;
    //this->setRawBits(rawBits + 256); //1 em rawbits (2^8=256)
    this->rawBits++;
    return (pre);
}

Fixed &Fixed::operator++(void)
{
    //this->setRawBits(rawBits + 256); //1 em rawbits (2^8=256)
    this->rawBits++;
    return (*this);
}

Fixed Fixed::operator--(int decrement)
{
    Fixed pre(*this);
    (void) decrement;
    //this->setRawBits(rawBits - 256); //1 em rawbits (2^8=256)
    this->rawBits--;
    return (pre);
}

Fixed &Fixed::operator--(void)
{
    //this->setRawBits(rawBits - 256); //1 em rawbits (2^8=256)
    this->rawBits--;
    return (*this);
}


const Fixed& Fixed::min(const Fixed &fixed1,const Fixed &fixed2)
{
    if(fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed2);
    return (fixed1);
}

Fixed& Fixed::min(Fixed &fixed1,Fixed &fixed2)
{
    if(fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed2);
    return (fixed1);
}

const Fixed& Fixed::max(const Fixed &fixed1,const Fixed &fixed2)
{
    if(fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed1);
    return (fixed2);
}

Fixed& Fixed::max(Fixed &fixed1,Fixed &fixed2)
{
    if(fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed1);
    return (fixed2);
}

