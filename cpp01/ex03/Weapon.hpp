#pragma once

#include <iostream>
#include <cstdio>
#include <iomanip>

class Weapon
{
    private:
        std::string type;
        
    public:
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string);
    std::string getType(void);
};

