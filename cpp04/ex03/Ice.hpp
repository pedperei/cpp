#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{    
    public:
        Ice();
        Ice(std::string type);
        Ice(const Ice&);
        ~Ice();
        Ice &operator=(const Ice &ice);
        Ice *clone() const;
};

