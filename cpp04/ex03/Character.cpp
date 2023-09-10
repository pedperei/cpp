#include "Character.hpp"


Character::Character():name("")
{
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
}

Character::Character(std::string name):name(name)
{
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
}

Character::~Character(){}

Character &Character::operator=(const Character &character)
{
    if(this != &character)
    {
        this->name = character.name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = character.inventory[i];
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m || m->getType().empty())
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
        {
            this->inventory[i] = m;
        }
    }
}

void unequip(int idx);

void use(int idx, ICharacter& target);