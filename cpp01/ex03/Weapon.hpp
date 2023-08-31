#pragma once

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h> 

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

