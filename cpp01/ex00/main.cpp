#include "Zombie.hpp"

int main (void)
{
    Zombie *asd =Zombie::newZombie("asd");
    asd->announce();
    delete asd;

    randomChump("random");
}