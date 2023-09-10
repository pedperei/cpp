#pragma once

#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
        AMateria *tmp_inv[100];
    public:
        Character();
        Character(std::string name);
        Character(const Character&);
        ~Character();
        Character &operator=(const Character &character);
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};