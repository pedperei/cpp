#pragma once

#include "Animal.hpp"

class Cat: public Animal
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
