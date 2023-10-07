#include "RPN.hpp"

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            RPN rpn;
            std::cout << rpn.parse_input(argv[1]) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}