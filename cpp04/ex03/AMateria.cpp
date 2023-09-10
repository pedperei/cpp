#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::AMateria()
{
    this->type = "";
}
        
AMateria::AMateria(const AMateria &amateria)
{
    *this = amateria;
}
        
AMateria::~AMateria()
{

}

AMateria& AMateria::operator=(const AMateria &amateria)
{
    if(this != &amateria)
    {
        this->type = amateria.type;
    }
    return (*this);
}