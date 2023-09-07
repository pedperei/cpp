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
    ClapTrap();
    ClapTrap(const ClapTrap&);
    ClapTrap(std::string Name);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &p);
    void setHit(int Hit);
    void setEnergy(int Energy);
    void setDamage(int Damage);
    int getHit(void);
    int getEnergy(void);
    int getDamage(void);
    std::string getName(void);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
