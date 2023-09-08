#pragma once

#include <iostream>

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
        virtual void makeSound() const;
};

