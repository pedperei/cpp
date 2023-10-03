#include "BitcoinExchange.hpp"

int main(void)
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
}