#include "Zombie.hpp"

int main (void)
{
    Zombie *asd =newZombie("asd");
    asd->announce();
    delete asd;

    randomChump("random");
}