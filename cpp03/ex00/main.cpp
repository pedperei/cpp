#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap clap1("111");
    ClapTrap clap2("222");
    ClapTrap clap3("333");

    clap1.setDamage(3);
    clap2.setDamage(4);
    clap3.setDamage(5);

    std::cout << std::endl;

    clap1.attack("Dog");
    clap1.getEnergy();
    clap1.getDamage();
    clap1.getHit();
    clap1.takeDamage(5);
    clap1.getHit();
    clap1.takeDamage(6);
    clap1.getHit();
    clap1.attack("Dog");
    clap1.getEnergy();

    std::cout << std::endl;

    clap2.getEnergy();
    clap2.getDamage();
    clap2.getHit();
    clap2.takeDamage(5);
    clap2.getHit();
    clap2.beRepaired(7);
    clap2.getHit();
    clap2.attack("Cat");
    clap2.getEnergy();

    std::cout << std::endl;

    clap3.getEnergy();
    clap3.getDamage();
    clap3.getHit();
    clap3.takeDamage(10);
    clap3.attack("Bear");
    clap3.attack("Bear");
    clap3.setEnergy(3);
    clap3.setHit(2);
    clap3.beRepaired(7);
    clap3.attack("Bear");
    clap3.getEnergy();

    std::cout << std::endl;
}