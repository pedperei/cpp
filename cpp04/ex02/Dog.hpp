#pragma once

#include "AAnimal.hpp"

class Dog: public AAnimal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog&);
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound() const;
        Brain *getBrain() const;
};
