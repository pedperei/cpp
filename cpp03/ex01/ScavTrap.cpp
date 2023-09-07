#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("Default")
{
    std::cout << this->getName() << " - Default constructor has been called - ScavTrap" << std::endl;
    this->setHit(100);
    this->setEnergy(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name)
{
    std::cout << this->getName() << " - Name constructor has been called - ScavTrap" << std::endl;
    this->setHit(100);
    this->setEnergy(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &scav)
{
    std::cout << this->getName() << " - Copy constructor has been called - ScavTrap" << std::endl;
    *this = scav;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->getName() << " - Destructor has been called - ScavTrap" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &p)
{
    if (this != &p)
    {
        ClapTrap::operator=(p);
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (this->getEnergy() > 0 && this->getHit() > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << 
            ", causing " << this->getDamage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergy() - 1);
    }
    else
    {
        std::cout << "ScavTrap " << this->getName() << 
            " can't attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode!" << std::endl;
}

