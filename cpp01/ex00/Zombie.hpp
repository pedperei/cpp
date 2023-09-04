#include <iostream>
#include <cstdio>
#include <iomanip>

class Zombie
{
    private:
        std::string name;

    public:
    Zombie();
    ~Zombie();
    void setName(std::string);
    void announce(void);
    static Zombie* newZombie(std::string name);
};


void randomChump(std::string name);