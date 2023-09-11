#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &name)
{
    for (int i = 0; i < 4; i++)
    {
        if(this->inventory[i]->getType() == name)
            return (this->inventory[i]->clone());
    }
    return (0);
}