#include "Array.tpp"

int main (void)
{
    Array<int> asd =Array<int>(32);
    for (int i = 0; i < 32; i++)
        asd.getArr()[i] = i;
    std::cout << asd.getArr()[2] << std::endl;
}