#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap scav0; 
    ScavTrap scav1("111");
    ScavTrap scav2("222");

    ClapTrap *clap1 = new ScavTrap("333");
    ClapTrap clap2 = ScavTrap("444");
    std:: cout << scav1.getHit() << std::endl;
    /* std:: cout << scav2.getHit() << std::endl;
    clap1->attack("dog"); 
    clap2.attack("dog");
    scav2.attack("dog");
    scav2.guardGate();*/
    (void) clap1;
}