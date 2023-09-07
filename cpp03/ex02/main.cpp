#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap a; 
    ClapTrap c("qwe");
    ScavTrap lol("asd");

    ClapTrap *d = new ScavTrap("teste123");
    ClapTrap e = ScavTrap("teste456");
    c.getHit();
    lol.getHit();
    d->attack("dog"); 
    e.attack("dog");
    lol.attack("dog");
    lol.guardGate();
}