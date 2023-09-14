#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat: constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat):WrongAnimal(wrongCat)
{
    *this = wrongCat;
    std::cout << "WrongCat: constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    if (this != &wrongCat)
    {
        this->type = wrongCat.type;
    }
    std::cout << "WrongCat: assignment operator called" << std::endl;
    return (*this);    
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meow" << std::endl;
}