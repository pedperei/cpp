#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::ifstream ifile;
    std::string contents;
    std::string buff;

    (void)argc;
    (void)argv;
    /* ifile.open("data.csv");
    if (!(ifile.is_open()))
        return (0); */
    
    BitcoinExchange *base = new BitcoinExchange();
    /* while (std::getline(ifile, buff))
        base->extract_date_value(buff,',', 0);
    ifile.close();*/
    ifile.open("data.csv");
    if (!(ifile.is_open()))
        return (0);
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,',', 0);
    ifile.close();

    ifile.open(argv[1]);
    if (!(ifile.is_open()))
        return (0);
    while (std::getline(ifile, buff))
        base->extract_date_value(buff,'|', 1);
    ifile.close();
   /*  std::cout << base->getBitcoinMap().size() << std::endl;
    for (std::map<std::string, float>::iterator it = base->getBitcoinMap().begin(); it != base->getBitcoinMap().end(); it++) 
    {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    } */
    /* std::map<std::string, float>::iterator it;
    std::map<std::string, float> bitcoinMap = base->getBitcoinMap();

    for (it = bitcoinMap.begin(); it != bitcoinMap.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
    std::cout << std::endl; */
}
