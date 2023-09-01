#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "[Wrong number of arguments]" << std::endl;
    else
    {
        Harl harl;
        harl.complain(argv[1]);
    }
}