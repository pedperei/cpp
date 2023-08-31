#pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;
        
    public:
    HumanA(std::string, Weapon&);
    ~HumanA();
    void setName(std::string);
    std::string getName(void);
    void attack(void);
};

