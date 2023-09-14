#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::Dog(const Dog &dog):AAnimal(dog)
{
    this->brain = new Brain();
    *this = dog;
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog: destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
        *this->brain = *dog.brain;
    }
    std::cout << "Dog: assignment operator called" << std::endl;
    return (*this);    
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}