#include "Ice.hpp"

Ice::Ice():AMateria("ice"){}

Ice::Ice(std::string type):AMateria(type){}
        
Ice::Ice(const Ice &ice)
{
    *this = ice;
}
        
Ice::~Ice(){}

Ice &Ice::operator=(const Ice &ice)
{
    return((Ice &)AMateria::operator=(ice));
}

Ice *Ice::clone() const
{
    Ice *newIce = new Ice("ice");
    return (newIce);
}

void Ice::use(ICharacter &character)
{
    std::cout << "* shoots an ice bolt at " << character.getName() << " *" << std::endl;
}