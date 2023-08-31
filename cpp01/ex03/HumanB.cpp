#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::setName(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

std::string HumanB::getName()
{
    return (this->name);
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType();
}