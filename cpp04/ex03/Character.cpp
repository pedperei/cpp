#include "Character.hpp"

Character::Character():name("Default")
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

Character::Character(const Character &character)
{
	*this = character;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character &Character::operator=(const Character &character)
{
	if (this != &character)
	{
		this->name = character.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
		}
		for (int i = 0; i < 4; i++)
			this->inventory[i] = character.inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

int Character::check_address(AMateria *addr)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == addr)
			return (0);
	}
	return (1);
}

void Character::equip(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "Materia passed is NULL" << std::endl;
		return ;
	}
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
		{
			if(!this->check_address(materia))
			{
				std::cout << "Materia already exists in inventory (same memory address)" << std::endl;
				return ;
			}
			else
			{
            	this->inventory[i] = materia;
				return ;
			}
		}
    }
	std::cout << "Inventory is already full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index passed is out of bounds" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			if (this->inventory[i])
			{
				this->inventory[i] = NULL;
				std::cout << "Materia Unequiped" << std::endl;
				return ;
			}
		}
	}
	std::cout << "Materia not in inventory" << std::endl;
}


void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index out of bounds" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == idx && this->inventory[i])
		{
            this->inventory[i]->use(target);
			return ;
		}
	}
	std::cout << "Index don't have Materia equiped" << std::endl;
}