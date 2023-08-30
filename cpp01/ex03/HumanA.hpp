#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon weapon;
        std::string name;
        
    public:
    HumanA();
    ~HumanA();
    void setName(std::string);
    const std::string &getType();
};

