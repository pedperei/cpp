#include "Character.hpp"

Character::Character()
	: name("Default")
{
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(std::string name)
	: name(name)
{
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character &Character::operator=(const Character &character)
{
	Character *newChar = new Character();
	if (this != &character)
	{
		newChar->name = character.name;
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			newChar->inventory[i] = character.inventory[i];
		return (*newChar);
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
		{
            this->inventory[i] = materia;
			break;
		}
    }
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			this->inventory[i] = NULL;
		}
	}
}


void Character::use(int idx, ICharacter &target)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
            this->inventory[i]->use(target);
		}
	}
}