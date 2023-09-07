#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("Default")
{
    std::cout << "Default constructor has been called - ScavTrap" << std::endl;
    this->setHit(100);
    this->setEnergy(100);
    this->setHit(30);
}

FragTrap::FragTrap(std::string Name):ClapTrap(Name)
{
    std::cout << "Name constructor has been called - ScavTrap" << std::endl;
    this->setHit(100);
    this->setEnergy(100);
    this->setHit(30);
}

FragTrap::FragTrap(const FragTrap &frag)
{
    std::cout << this->getName() << " - Copy constructor has been called - FragTrap" << std::endl;
    *this = frag;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor has been called - FragTrap" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &p)
{
    if (this != &p)
    {
        ClapTrap::operator=(p);
    }
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (this->getEnergy() > 0 && this->getHit() > 0)
    {
        std::cout << "FragTrap " << this->getName() << " attacks " << target << 
            ", causing " << this->getDamage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergy() - 1);
    }
    else
    {
        std::cout << "FragTrap " << this->getName() << 
            " can't attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " is requesting a high five..." << std::endl;
    std::cout << "High five accespted!" << std::endl;
}

