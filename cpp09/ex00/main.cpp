#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::ifstream ifile;
    std::string contents;
    std::string buff;

    
    if (argc > 2)
    {
        std::cerr << "Error: too many arguments passed." << std::endl;
        return (0);
    }
    BitcoinExchange *base = new BitcoinExchange();
    ifile.open("data.csv");
    if (!(ifile.is_open()))
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (0);
    }

    std::getline(ifile, buff);
    if (!base->check_header(buff, ',', 0))
        return (0);
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,',', 0);
    ifile.close();

    ifile.open(argv[1]);
    if (!(ifile.is_open()))
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (0);
    }
    std::getline(ifile, buff);
    if (!base->check_header(buff, '|', 1))
        return (0);
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,'|', 1);
    ifile.close();
   delete base;
}
