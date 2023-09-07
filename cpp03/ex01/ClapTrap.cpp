#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << this->getName() << " - Default constructor has been called - ClapTrap" << std::endl;
    this->Name = "Default";
    this->Hit = 10;
    this->Energy = 10;
    this->Damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
    std::cout << this->getName() << " - Copy constructor has been called - ClapTrap" << std::endl;
    *this = clap;
}

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << this->getName() << " - Name constructor has been called - ClapTrap" << std::endl;
    this->Name = Name;
    this->Hit = 10;
    this->Energy = 10;
    this->Damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->getName() << " - Destructor has been called - ClapTrap" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &p)
{
    if (this != &p)
    {
        this->Name = p.Name;
        this->Hit = p.Hit;
        this->Energy = p.Energy;
        this->Damage = p.Damage;
    }
    return (*this);
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

std::string ClapTrap::getName(void)
{
    return (this->Name);
}


int ClapTrap::getHit(void)
{
    //std::cout << "ClapTrap " << this->Name << " has " << this->Hit << " point of Hit!" << std::endl;
    return (this->Hit);
}

int ClapTrap::getEnergy(void)
{
    //std::cout << "ClapTrap " << this->Name << " has " << this->Energy << " point of Energy!" << std::endl;
    return (this->Energy);
}

int ClapTrap::getDamage(void)
{
    //std::cout << "ClapTrap " << this->Name << " has " << this->Damage << " point of Damage!" << std::endl;
    return (this->Damage);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attacks " << target << 
            ", causing " << this->Damage << " points of damage!" << std::endl;
        this->Energy--;
    }
    else
    {
        std::cout << "ClapTrap " << this->Name << 
            " can't attack!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "ClapTrap " << this->Name << " repairs " << amount << 
            " Hit points!" << std::endl;
        this->Energy--;
        this->Hit += amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->Name << 
            " can't repair!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > 0)
    {
        std::cout << "ClapTrap " << this->Name << " has taken " << amount << 
            " points of damage!" << std::endl;
        this->Hit -= amount;
        if (this->Hit < 0)
            this->Hit = 0;
    }
    else
        std::cout << "ClapTrap already has 0 Hit points" << std::endl;
}