#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *newZombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        newZombies[i].setName(name);
        std::cout << i + 1;
        newZombies[i].announce();
    }
    return (newZombies);
}