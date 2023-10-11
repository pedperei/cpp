#include "RPN.hpp"

int main (int argc, char **argv)
{
    if (argc > 1)
    {
        std::stringstream s_input;
        int i = 1;
        while (argv[i])
        {
            s_input << argv[i] << " ";
            i++;
        }
        try
        {
            RPN rpn;
            std::cout << rpn.parse_input(s_input.str()) << std::endl;
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