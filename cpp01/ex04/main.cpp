#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments inserted" << std::endl;
    }
    else
    {
        File file;
        if (!(file.replace(argv[1], argv[2], argv[3])))
            std::cout << "Failed to open file" << std::endl;
    }
}

/* int main(void)
{
    File file;

    file.replace("teste1", "a", "b");
    file.replace("teste2", "c", "d");
    file.replace("teste3", "e", "f");
} */