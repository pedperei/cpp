#include "Fixed.hpp"

Fixed::Fixed(const int rawBits)
{
    std::cout << "Default constructor called" << std::endl;
    this->rawBits=rawBits;
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


