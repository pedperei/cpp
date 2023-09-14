#pragma once

#include "AAnimal.hpp"

class Cat: public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat&);
        ~Cat();
        Cat &operator=(const Cat &cat);
        void makeSound() const;
        Brain *getBrain() const;
};
