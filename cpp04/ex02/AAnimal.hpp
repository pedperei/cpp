#pragma once

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal&);
        virtual ~AAnimal();
        AAnimal &operator=(const AAnimal&);
        std::string getType() const;
        virtual Brain *getBrain() const;
        virtual void makeSound() const = 0;
};
