#include "ClapTrap.hpp"

/* ClapTrap::ClapTrap()
{
    std::cout << "Default constructor has been called" << std::endl;
    this->Name = "Default";
    this->Hit = 10;
    this->Energy = 10;
    this->Attack = 0;
} */

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << "Name constructor has been called" << std::endl;
    this->Name = Name;
    this->Hit = 10;
    this->Energy = 10;
    this->Damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << this->Name << "attacks " << target << 
        ", causing " << this->Damage << "points of damage!" << std::endl;
}