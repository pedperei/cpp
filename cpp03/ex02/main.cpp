#include "FragTrap.hpp"

int main (void)
{
    FragTrap frag1("111");

    std:: cout << "Hit points:" << frag1.getHit() << std::endl;
    std:: cout << "Energy Points:" << frag1.getEnergy() << std::endl;
    frag1.attack("dog");
    frag1.attack("dog");
    std:: cout << "Energy Points:" << frag1.getEnergy() << std::endl;
    frag1.takeDamage(32); 
    std:: cout << "Hit Points:" << frag1.getHit() << std::endl; 
    frag1.highFivesGuys();

    frag1.beRepaired(32);
    std:: cout << "Hit Points:" << frag1.getHit() << std::endl;
    std:: cout << "Energy Points:" << frag1.getEnergy() << std::endl;

    frag1.takeDamage(100);
    std:: cout << "Hit Points:" << frag1.getHit() << std::endl;
    frag1.beRepaired(20);
}