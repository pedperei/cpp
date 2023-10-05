#pragma once

#include <iostream>
#include <cstdlib>
#include <map>
#include <limits>
#include <fstream>
#include <algorithm>
#include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, float> bitcoinMap;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& bitcoinExchange);

    int extract_date_value(std::string input, char sep, int exchange);
    int fill_exchange(char sep, int exchange);
    int check_date(std::string date);
    int check_value(std::string nbr, int exchange);


    std::map<std::string, float> getBitcoinMap();

    /* class CustomException : public std::exception 
    {
        private:
            std::string errorMessage;

        public:
            CustomException(const std::string& message) : errorMessage(message) {}

        virtual const char* what() const throw()
        {
            return errorMessage.c_str();
        }
    }; */
};
