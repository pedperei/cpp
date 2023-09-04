#pragma once

#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int Hit;
    int Energy;
    int Damage;
public:
    ClapTrap(std::string Name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
