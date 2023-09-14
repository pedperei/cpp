#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    int size = 10;
    Animal *animals[size];

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
        if (i < size /2)
        {
            animals[i]->getBrain()->getIdeas()[0] = "I need to eat";
            animals[i]->getBrain()->getIdeas()[1] = "i need to chase a cat";
            std::cout << animals[i]->getBrain()->getIdeas()[i % 2] << std::endl;
        }
        else
        {
            animals[i]->getBrain()->getIdeas()[0] = "I need to eat";
            animals[i]->getBrain()->getIdeas()[1] = "i need to run way from the dog";
            std::cout << animals[i]->getBrain()->getIdeas()[i % 2] << std::endl;
        }
    }
    Dog asd = Dog((Dog &)*animals[size/3]);
    std::cout << std::endl << std::endl << asd.getType() << ":" << std::endl;
    std::cout << std::endl << asd.getBrain()->getIdeas()[0];
    std::cout << std::endl << asd.getBrain()->getIdeas()[1] << std::endl << std::endl;
    Cat qwe = Cat((Cat &)*animals[size - 1]);
    std::cout << std::endl << qwe.getType() << ":" << std::endl;
    std::cout << std::endl << qwe.getBrain()->getIdeas()[0];
    std::cout << std::endl << qwe.getBrain()->getIdeas()[1] << std::endl << std::endl;

    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
    return 0;
}