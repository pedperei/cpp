#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain: destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain: copy constructor called" << std::endl;
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    if(this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    std::cout << "Brain: assignment operator called" << std::endl;
    return (*this);
}
