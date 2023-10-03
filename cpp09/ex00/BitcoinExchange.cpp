#include "BitcoinExhange.hpp"

bool check_zero(std::string date) 
{
    int flag = 0;
    for (char c : date) 
    {
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
    for (char c : nbr) 
    {
        if (!std::isdigit(c))
            return (0);
        i++;
    }
    return (i);
}

int check_value(std::string nbr) 
{
    int i = 0;
    int flag = 0;
    for (char c : nbr) 
    {
        if (!std::isdigit(c) && (c != '.' && !flag))
            return (0);
        i++;
        if (c == '.')
            flag++;
    }
    if (check_zero(nbr))
        return (1);
    double value = std::atof(nbr);
    if (value < 0 && value > 1000)
        return (0);
    return (1);
}

bool check_year(std::string date) 
{
    if (check_zero(date))
        return (1);
    for (char c : date) 
    {
        if (c != '0' && c != '.' && c != '-')
            return (0);
    }
    return (1);
}

int BitcoinExchange::check_date(std::string date)
{
    std::string temp = date;
    std::size_t pos_1 = temp.find("-");
    if (pos_1 == std::string::npos)
        return (0);
    std::string year_str = temp.substr(0,pos_1 - 1);
    if (!count_digits(year_str) && count_digits(year_str) > 9)
        return (0);

    temp = temp.substr(pos_1 + 1);
    std::size_t pos_2 = str.find("-");
    if (pos_1 == std::string::npos)
        return (0);
    std::string month_str = temp.substr(0,pos_2 - 1);
    int month = std::atoi(month_str.c_str());
    if (!count_digits(month_str) && count_digits(month_str) != 2 && month < 1 && month > 12)
        return (0);

    temp = temp.substr(pos_2 + 1);
    std::string day_str = temp;
    int day = std::atoi(day_str.c_str());
    if (!count_digits(day_str) && count_digits(day_str) != 2 && day < 1 && day > 31)
        return (0);
    return (1);
}



int BitcoinExchange::extract_date_value(std::string input)
{
    std::size_t pos = str.find("|");
    if (pos == std::string::npos)
        return (0);
    std::string date = input.substr(0, pos - 2);
    if (!check_date(date))
        return (0);
    std::string value = input.substr(pos + 2);
    if (!check_value(value))
        return (0);
    this->bitcoinMap[date] = value;
    return (1);
}

