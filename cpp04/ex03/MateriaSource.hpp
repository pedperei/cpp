#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource&);
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &materiaSource);
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const &type);
};