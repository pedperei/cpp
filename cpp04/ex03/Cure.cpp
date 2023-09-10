#include "Cure.hpp"

Cure::Cure()
{
    this->type = "";
}

Cure::Cure(std::string type)
{
    this->type = "cure";
}
        
Cure::Cure(const Cure &cure)
{
    *this = cure;
}
        
Cure::~Cure()
{

}

Cure &Cure::operator=(const Cure &cure)
{
    if(this != &cure)
    {
        this->type = cure.type;
    }
    return (*this);
}

Cure *Cure::clone() const
{
    Cure *newCure = new Cure("cure");
    return (newCure);
}