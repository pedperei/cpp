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
    std::string buff;
    int s1len = s1.length();
    int pos;

    ifile.open(name.c_str());
    if (!(ifile.is_open()))
        return (0);
    while (std::getline(ifile, buff))
    {
        contents += (buff + "\n");
    }
    contents.erase(contents.length()-1,1);
    ifile.close();
    while (contents.find(s1) != std::string::npos)
    {
        pos = contents.find(s1);
        contents.erase(pos, s1len);
        contents.insert(pos, s2);
    }
    ofile.open((name + ".replace").c_str());
    if(!(ofile.is_open()))
        return (0);
    ofile << contents;
    ofile.close();
    return (1);
}