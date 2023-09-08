#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
    *this = cat;
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
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