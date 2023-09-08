#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal&);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal&);
        std::string getType() const;
        virtual void makeSound() const;
};

