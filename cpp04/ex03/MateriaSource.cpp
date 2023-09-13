#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource()
{
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    *this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if(this != &materiaSource)
    {
        for (int i = 0; i < 4; i++)
            delete this->inventory[i];
        for (int i = 0; i < 4; i++)
            this->inventory[i] = materiaSource.inventory[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
    }
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