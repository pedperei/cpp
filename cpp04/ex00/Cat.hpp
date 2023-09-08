#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat&);
        ~Cat();
        Cat &operator=(const Cat &cat);
        void makeSound() const;
};

