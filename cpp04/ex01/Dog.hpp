#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog&);
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound() const;
};
