#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal&);
        virtual ~Animal();
        Animal &operator=(const Animal&);
        std::string getType() const;
        virtual Brain *getBrain() const;
        virtual void makeSound() const;
};

