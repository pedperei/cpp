#include "AMateria.hpp"

AMateria::AMateria(std::string const &type):type(type){}

AMateria::AMateria():type(""){}
        
AMateria::AMateria(const AMateria &amateria)
{
    *this = amateria;
}
        
AMateria::~AMateria(){}

AMateria& AMateria::operator=(const AMateria &amateria)
{
    if(this != &amateria)
    {
        this->type = amateria.type;
    }
    return (*this);
}


void AMateria::use(ICharacter& target)
{
    std::cout << "Default instruction " << target.getName() << std::endl;
}

std::string const &AMateria::getType() const
{
    return (this->type);
}