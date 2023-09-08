#pragma once

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain&);
        ~Brain();
        Brain &operator=(const Brain&);
        std::string *getIdeas();
};
