#pragma once

#include <iostream>
#include <cstdlib>
#include <map>
#include <limits>

class BitcoinExchange
{
private:
    std::map<std::string, float> bitcoinMap;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& bitcoinExchange);
    extract_date(std::string input);
    check_date(std::string input);
}
