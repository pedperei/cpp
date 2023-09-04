#include "Zombie.hpp"

Zombie::Zombie()
{

}
Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie *Zombie::newZombie(std::string name)
{
    Zombie *newZombie = new Zombie;
    newZombie->setName(name);
    return (newZombie);
}
