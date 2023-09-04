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

void ClapTrap::setHit(int Hit)
{
    this->Hit = Hit;
}

void ClapTrap::setEnergy(int Energy)
{
    this->Energy = Energy;
}

void ClapTrap::setDamage(int Damage)
{
    this->Damage = Damage;
}

int ClapTrap::getHit(void)
{
    return (this->Hit);
}

int ClapTrap::getEnergy(void)
{
    return (this->Energy);
}

int ClapTrap::getDamage(void)
{
    return (this->Damage);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "ClapTrap " << this->Name << "attacks " << target << 
            ", causing " << this->Damage << "points of damage!" << std::endl;
        this->Energy--;
    }
    else
    {
        std::cout << "ClapTrap " << this->Name << 
            "can't attack!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "ClapTrap " << this->Name << "repairs " << amount << 
            "Hit points!" << std::endl;
        this->Energy--;
        this->Hit += amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->Name << 
            "can't repair!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->Hit)
        amount = this->Hit;
    if (amount > 0)
        std::cout << "ClapTrap " << this->Name << "has taken " << amount << 
            "points of damage!" << std::endl;
    else
        std::cout << "ClapTrap already has 0 Hit points" << std::endl;
    this->Hit -= amount;
}