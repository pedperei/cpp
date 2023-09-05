#include "Fixed.hpp"

static	float power_2(int exp)
{
	float   val = 0;

	if (exp == 0)
		return (val);
    val = 2;
	while (--exp)
		val = val * 2;
	return (val);
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->rawBits=0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int rawBits)
{
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = rawBits * power_2(this->fractBits);
}

Fixed::Fixed(const float rawBits)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(rawBits * power_2(this->fractBits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    
	std::cout << "Copy assignment operator called" << std::endl;
    this->rawBits=fixed.rawBits;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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
