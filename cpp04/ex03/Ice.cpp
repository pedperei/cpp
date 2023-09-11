#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(std::string type)
{
    this->type = type;
}
        
Ice::Ice(const Ice &ice)
{
    *this = ice;
}
        
Ice::~Ice()
{

}

Ice &Ice::operator=(const Ice &ice)
{
    if(this != &ice)
    {
        this->type = ice.type;
    }
    return (*this);
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