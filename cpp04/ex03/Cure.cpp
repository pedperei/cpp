#include "Cure.hpp"

Cure::Cure():AMateria("cure"){}

Cure::Cure(std::string type):AMateria(type){}
        
Cure::Cure(const Cure &cure)
{
    *this = cure;
}
        
Cure::~Cure(){}

Cure &Cure::operator=(const Cure &cure)
{
    return((Cure &)AMateria::operator=(cure));
}

Cure *Cure::clone() const
{
    Cure *newCure = new Cure("cure");
    return (newCure);
}

void Cure::use(ICharacter &character)
{
    std::cout << "* heals " << character.getName() << "’s wounds *" << std::endl;
}