#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal: constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal: copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    if(this != &animal)
    {
        this->type = animal.type;
    }
    std::cout << "Animal: assignment operator called" << std::endl;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Choose a specific Animal to make sound" << std::endl;
}