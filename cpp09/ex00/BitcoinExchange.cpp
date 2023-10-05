#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinExchange)
{
    *this = bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitcoinExchange)
{
    if (this != &bitcoinExchange)
    {
        this->bitcoinMap = bitcoinExchange.bitcoinMap;
    }
    return (*this);
}

bool check_zero(std::string date) 
{
    int flag = 0;
    char c;
    for (size_t i = 0; i < date.length(); ++i)
    {
        c = date[i];
        if (c != '0' && (c != '.' && !flag))
            return (0);
        if (c == '.')
        flag++;
    }
    return (1);
}

int count_digits(std::string nbr) 
{
    int i = 0;
    char c;
    for (size_t i = 0; i < nbr.length(); ++i)
    {
        c = nbr[i];
        if (!std::isdigit(c))
        {

            return (0);
        }
        i++;
    }
    return (i);
}

int BitcoinExchange::check_value(std::string nbr, int exchange) 
{
    int flag = 0;
    char c;
    for (size_t i = 0; i < nbr.length(); ++i)
    {
        c = nbr[i];
        if (!std::isdigit(c) && (c != '.' && !flag) && (c != '.' && i == 0))
            throw std::runtime_error("Error: Non numeric char in number");
        i++;
        if (c == '.')
            flag++;
    }
    if (check_zero(nbr))
        return (1);
    double value = std::atof(nbr.c_str());
    if (value < 0)
        throw std::runtime_error("Error: Value < 0");
    if (value > 1000 && exchange == 1)
        throw std::runtime_error("Error: Value > 1000");
    return (1);
}

int BitcoinExchange::check_date(std::string date)
{
    std::string temp = date;
    std::size_t pos_1 = temp.find("-");
    if (pos_1 == std::string::npos)
        throw std::runtime_error("Error: Missing '-' separator in date");

    std::string year_str = temp.substr(0,pos_1 - 1);
    if (!count_digits(year_str) && count_digits(year_str) > 9)
        throw std::runtime_error("Error: Year is not correct");

    temp = temp.substr(pos_1 + 1);
    std::size_t pos_2 = temp.find("-");
    if (pos_1 == std::string::npos)
        throw std::runtime_error("Error: Missing '-' separator in date");
    std::string month_str = temp.substr(0,pos_2 - 1);
    int month = std::atoi(month_str.c_str());
    if (!count_digits(month_str) && count_digits(month_str) != 2 && month < 1 && month > 12)
        throw std::runtime_error("Error: Month is not correct");

    temp = temp.substr(pos_2 + 1);
    std::string day_str = temp;
    int day = std::atoi(day_str.c_str());
    if (!count_digits(day_str) && count_digits(day_str) != 2 && day < 1 && day > 31)
        throw std::runtime_error("Error: Day is not correct");
    return (1);
}



int BitcoinExchange::extract_date_value(std::string input, char sep, int exchange)
{
    try
    {
        std::size_t pos = input.find(sep);
        if (pos == std::string::npos)
            throw std::runtime_error("Error: Missing separator");
        std::string date = input.substr(0, pos - exchange);
        if (!check_date(date))
            return (0);
        std::string value = input.substr(pos + 1 + exchange);
        if (!check_value(value, exchange))
            return (0);
        if (exchange == 0)
        {
            std::pair<std::string, float> tempPair = std::make_pair(date, (float)atof(value.c_str()));
            //std::cout << "Date: " << tempPair.first << ", Value: " << tempPair.second << std::endl;
            this->bitcoinMap.insert(tempPair);
        }
        else
        {
            std::cout << date << " " << value << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (1);
}

std::map<std::string, float> BitcoinExchange::getBitcoinMap()
{
    return (this->bitcoinMap);
}
