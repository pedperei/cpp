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
    size_t i = 0;
    char c;
    for (i = 0; i < nbr.length(); i++)
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
        if (!(std::isdigit(c) || (c == '.' && !flag) || (c == '-' && i == 0)))
            throw std::runtime_error("Error: Non numeric char in number => " + nbr);
        i++;
        if (c == '.')
            flag++;
    }
    if (check_zero(nbr))
        return (1);
    double value = std::atof(nbr.c_str());
    if (value < 0)
        throw std::runtime_error("Error: not a positive number.");
    if (value > 1000 && exchange == 1)
        throw std::runtime_error("Error: too large a number.");
    return (1);
}

bool is_bissextile_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return (1);
            else
                return (0);
        }
        else
            return (1);
    }
    return (0);
}


int check_year_month_day(int year, int month, int day)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return (0);
    }
    else if (month == 2)
    {
        if (day > 29 || (day == 29 && !is_bissextile_year(year)))
            return (0);
    }
    return (1);
}

int BitcoinExchange::check_date(std::string date)
{
    std::string temp = date;
    std::size_t pos_1 = temp.find("-");
    if (pos_1 == std::string::npos)
        throw std::runtime_error("Error: bad input => " + date);

    std::string year_str = temp.substr(0, pos_1);
    int year = std::atoi(year_str.c_str());
    if (!count_digits(year_str) || count_digits(year_str) > 9)
        throw std::runtime_error("Error: bad input => " + date);

    temp = temp.substr(pos_1 + 1);
    std::size_t pos_2 = temp.find("-");
    if (pos_1 == std::string::npos)
        throw std::runtime_error("Error: bad input => " + date);
    std::string month_str = temp.substr(0, pos_2);

    int month = std::atoi(month_str.c_str());
    if (!count_digits(month_str) || count_digits(month_str) != 2 || month < 1 || month > 12)
        throw std::runtime_error("Error: bad input => " + date);

    temp = temp.substr(pos_2 + 1);
    std::string day_str = temp;
    int day = std::atoi(day_str.c_str());
    if (!count_digits(day_str) || count_digits(day_str) != 2 || day < 1 || day > 31 || !check_year_month_day(year, month, day))
        throw std::runtime_error("Error: bad input => " + date);
    return (1);
}

int BitcoinExchange::check_header(std::string input, char sep, int exchange)
{
    try
    {
        std::size_t pos = input.find(sep);
        if (pos == std::string::npos)
            throw std::runtime_error("Error: Missing separator in header");
        std::string date = input.substr(0, pos - exchange);
        std::string value = input.substr(pos + 1 + exchange);
        if (!exchange)
        {
            if (!(date == "date" && value == "exchange_rate" && exchange == 0))
                throw std::runtime_error("Error: Wrong format in header");
        }
        else
        {
            if (!(date == "date" && value == "value" && exchange == 1))
                throw std::runtime_error("Error: Wrong format in header");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (0);
    }
    return (1);
}


int BitcoinExchange::extract_date_value(std::string input, char sep, int exchange)
{
    try
    {
        std::size_t pos = input.find(sep);
        if (pos == std::string::npos)
            throw std::runtime_error("Error: bad input => " + input);
        std::string date = input.substr(0, pos - exchange);
        if (!check_date(date))
            return (0);
        std::string value = input.substr(pos + 1 + exchange);
        if (!check_value(value, exchange))
            return (0);
        if (exchange == 0)
        {
            std::pair<std::string, float> tempPair = std::make_pair(date, atof(value.c_str()));
            //std::cout << "Date: " << tempPair.first << ", Value: " << tempPair.second << std::endl;
            this->bitcoinMap.insert(tempPair);
        }
        else
        {
            std::map<std::string, float>::iterator it = this->bitcoinMap.find(date);
            if (it != this->bitcoinMap.end())
                std::cout << date << " => " << value << " = " << (atof(value.c_str()) * (double)it->second) << std::endl;
            else
            {
                it = this->bitcoinMap.lower_bound(date);
                it--;
                std::size_t pos_1 = date.find("-");
                std::string year_str = date.substr(0, pos_1);
                double year_nbr = atof(year_str.c_str());
                if (year_nbr > 9999)
                {
                    it = this->bitcoinMap.end();
                    it--;
                }
                std::cout << std::fixed << std::setprecision(2) << date << " => " << value << " = " << (atof(value.c_str()) * (double)it->second) << std::endl;
            }
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
