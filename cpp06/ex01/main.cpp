#include "Serializer.hpp"

int main (void)
{
    Data *test = new Data();

    std::cout << test << std::endl;
    uintptr_t raw = Serializer::serialize(test);

    std::cout << raw << std::endl;

    test = Serializer::deserialize(raw);
    std::cout << test << std::endl;
    delete test;
}