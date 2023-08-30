#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h> 

class Weapon
{
    private:
        std::string type;
        
    public:
    Weapon();
    ~Weapon();
    void setType(std::string);
    std::string getType();
};

