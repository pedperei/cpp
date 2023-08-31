#pragma once

#include <iostream>
#include <fstream>
#include <string>

class File
{
    private:
        std::string name;
        std::string s1;
        std::string s2;
    public:
    File();
    ~File();
    int replace(std::string, std::string, std::string);
};


