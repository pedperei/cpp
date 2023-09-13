#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
    *this = dog;
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
    }
    std::cout << "Dog: assignment operator called" << std::endl;
    return (*this);    
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}