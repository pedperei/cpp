#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->type = "AAnimal";
    std::cout << "AAnimal: constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal)
{
    std::cout << "AAnimal: copy constructor called" << std::endl;
    *this = aanimal;
}

AAnimal &AAnimal::operator=(const AAnimal &aanimal)
{
    if(this != &aanimal)
    {
        this->type = aanimal.type;
    }
    std::cout << "AAnimal: assignment operator called" << std::endl;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->type);
}

void AAnimal::makeSound(void) const
{
    std::cout << "Choose a specific AAnimal to make sound" << std::endl;
}