#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{    
    public:
        Cure();
        Cure(std::string type);
        Cure(const Cure&);
        ~Cure();
        Cure &operator=(const Cure &cure);
        Cure *clone() const;
};

