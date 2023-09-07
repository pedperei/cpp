#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap scav1("111");

    std:: cout << "Hit points:" << scav1.getHit() << std::endl;
    std:: cout << "Energy Points:" << scav1.getEnergy() << std::endl;
    scav1.attack("dog");
    scav1.attack("dog");
    std:: cout << "Energy Points:" << scav1.getEnergy() << std::endl;
    scav1.takeDamage(32); 
    std:: cout << "Hit Points:" << scav1.getHit() << std::endl; 
    scav1.guardGate();
    scav1.takeDamage(70);
    std:: cout << "Hit Points:" << scav1.getHit() << std::endl;
    scav1.attack("dog");   
}