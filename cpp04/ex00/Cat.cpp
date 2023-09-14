#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::Cat(const Cat &cat):Animal(cat)
{
    *this = cat;
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
    }
    std::cout << "Cat: assignment operator called" << std::endl;
    return (*this);    
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}