#pragma once

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
        AAnimal();
    public:
        AAnimal(const AAnimal&);
        virtual ~AAnimal();
        AAnimal &operator=(const AAnimal&);
        std::string getType() const;
        virtual void makeSound() const;
};

