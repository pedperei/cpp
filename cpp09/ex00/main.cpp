#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::ifstream ifile;
    std::string contents;
    std::string buff;

    
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of arguments passed." << std::endl;
        return (0);
    }
    BitcoinExchange *base = new BitcoinExchange();
    ifile.open("data.csv");
    if (!(ifile.is_open()))
    {
        std::cerr << "Error: could not open file." << std::endl;
        delete base;
        return (0);
    }

    std::getline(ifile, buff);
    if (!base->check_header(buff, ',', 0))
    {
        delete base;
        return (0);
    }
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,',', 0);
    ifile.close();

    ifile.open(argv[1]);
    if (!(ifile.is_open()))
    {
        std::cerr << "Error: could not open file." << std::endl;
        delete base;
        return (0);
    }
    std::getline(ifile, buff);
    if (!base->check_header(buff, '|', 1))
    {
        delete base;
        return (0);
    }
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,'|', 1);
    ifile.close();
   delete base;
}
