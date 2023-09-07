#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    
public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap::FragTrap(const FragTrap&);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &p);
    void highFivesGuys(void);
    void attack(const std::string &target);
};
