#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    public:
        ~MateriaSource();
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const &type);
};