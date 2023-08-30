#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string Weapon::getType()
{
    return (this->type);
}

int main ()
{
    Weapon Weapon;

    Weapon.setType("asd");
    std::cout << Weapon.getType();
}

