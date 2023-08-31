#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
        
    public:
    HumanB(std::string);
    ~HumanB();
    void setName(std::string);
    std::string getName(void);
    void setWeapon(Weapon &weapon);
    void attack(void);
};

