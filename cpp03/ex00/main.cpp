#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap clap1("Clap111");
    ClapTrap clap2("Clap222");
    ClapTrap clap3("Clap333");

    clap1.setDamage(3);
    clap2.setDamage(4);
    clap3.setDamage(5);

    clap1.attack("dog");
}