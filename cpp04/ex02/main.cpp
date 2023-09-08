#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    int size = 10;
    AAnimal *animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "->" << animals[i]->getType() << ":";
        animals[i]->makeSound();
        std::cout << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
    return 0;
}