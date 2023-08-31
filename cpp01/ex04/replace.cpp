#include "replace.hpp"

File::File()
{

}

File::~File()
{
    
}

int File::replace(std::string name, std::string s1, std::string s2)
{
    std::ifstream ifile;
    std::ofstream ofile;
    std::string contents;
    int s1len = s1.length();
    int pos;

    ifile.open("test.txt");
    ifile >> contents;
    ifile.close();

    while (contents.find(s1) != std::string::npos)
    {
        pos = contents.find(s1);
        contents.erase(pos, s1len);
        contents.insert(pos, s2);
    }
    ofile.open(name.c_str());
    ofile << contents;

    (void)s1;
    (void)s2;
    (void)name;

    return (1);
}