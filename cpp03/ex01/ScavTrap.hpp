#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    
public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap&);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &p);
    void guardGate();
    void attack(const std::string &target);
};
