#include "replace.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    File file;
    file.replace(argv[1], argv[2], argv[3]);
}