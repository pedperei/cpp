#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
    }
    std::cout << std::endl << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }
    std::cout << std::endl << std::endl;
    {
        //Object slicing - occurs when you assign an object of a derived class
        //to an object of a base class, and as a result, the derived class object's extra data
        //or behavior is "sliced off," leaving only the common characteristics of the base class.
        //
        //If you want to avoid object slicing and retain the specific behavior of the derived class, 
        //you can use pointers or references instead of objects. 
        WrongAnimal *wcat_heap = new WrongCat();
        WrongAnimal wcat_stack =  *wcat_heap;
        WrongAnimal &wcat_ref =  *wcat_heap;
        wcat_heap->makeSound();
        wcat_stack.makeSound(); //called method of Main Class (object slicing)
        wcat_ref.makeSound();
        delete wcat_heap;
    }
    std::cout << std::endl << std::endl;
    {
        Animal *dog = new Dog();
        Animal *cat = new Cat();
        WrongAnimal *wrongCat = new WrongCat();

        dog->makeSound();
        cat->makeSound();
        wrongCat->makeSound();
        delete dog;
        delete cat;
        delete wrongCat;
    }
    return 0;
}