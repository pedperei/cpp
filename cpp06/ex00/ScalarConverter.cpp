#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
    *this=scalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarConverter)
{
    (void)scalarConverter;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(int i)
{
    if ((char)i >=32 && (char)i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void printFloat(float f)
{
    if (f == std::floor(std::abs(f)))
    {
        if ((char)f >=32 && (char)f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    }
    else
    {
        if ((char)f >=32 && (char)f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
}

void printDouble(double d)
{
    if (d == std::floor(std::abs(d)))
    {
        if ((char)d >=32 && (char)d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else
    {
        if ((char)d >=32 && (char)d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void printNanInf_f(float naninf)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << naninf << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(naninf) << std::endl;
}

void printNanInf(double naninf)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(naninf) << "f" << std::endl;
    std::cout << "double: " << naninf << std::endl;
}

void print_imp(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool is_integer(std::string literal)
{
    for (int i = 0; i < (int)literal.size(); i++)
    {
        if(!(literal[i] >= '0' && literal[i] <= '9') || ((literal[i] == '+' || literal[i] == '-') && i == 0))
            return (0);
    }
    return (1);
}

bool is_float(std::string literal)
{
    int flag = 0;
    int crit = 0;
    int size = (int)literal.size();
    for (int i = 0; i < size; i++)
    {
        if(((literal[i] >= '0' && literal[i] <= '9') || ((literal[i] == '+' || literal[i] == '-') && i == 0)
            || (literal[i] == '.') || (literal[i] == 'f' && i == (size - 1))) && (crit <= 1))
        {
            if (literal[i] == '.')
                crit++;
        }
        else
            flag = 1;
    }
    if (flag == 1 || literal[size - 1] != 'f')
        return (0);
    return (1);
}

bool is_double(std::string literal)
{
    int flag = 0;
    int crit = 0;
    int size = (int)literal.size();
    for (int i = 0; i < size; i++)
    {
        if(((literal[i] >= '0' && literal[i] <= '9') || ((literal[i] == '+' || literal[i] == '-') && i == 0)
            || (literal[i] == '.'))  && crit <= 1)
        {
            if (literal[i] == '.')
                crit++;
        }
        else
            flag = 1;
    }
    if (flag == 1)
        return (0);
    return (1);
}

bool is_nan_inf_f(std::string liberal)
{
    if (liberal == "-inff" || liberal == "+inff" || liberal == "nanf")
        return (1);
    return (0);
}

bool is_nan_inf(std::string liberal)
{
    if (liberal == "-inf" || liberal == "+inf" || liberal == "nan")
        return (1);
    return (0);
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.size() == 1 && (literal[0] >=32 && literal[0] <= 126)
            && !(literal[0] >=48 && literal[0] <= 57))
    {
        char c;
        c = static_cast<char>(literal[0]);
        printChar(c);
    }
    else if (is_integer(literal))
    {
        double temp = std::atof(literal.c_str());;
        if (temp >= INT_MIN && temp <= INT_MAX)
        {
            int i;
            i = std::atoi(literal.c_str());
            printInt(i);
        }
        else
        {
            double d;
            d = std::atof(literal.c_str());
            printDouble(d);
        }
    }
    else if (is_float(literal))
    {
        float f;
        f = std::atof(literal.c_str());
        printFloat(f);
    }
    else if (is_double(literal))
    {
        double d;
        d = std::atof(literal.c_str());
        printDouble(d);
    }
    else if (is_nan_inf_f(literal))
    {
        float f;
        f = std::atof(literal.c_str());
        printNanInf_f(f);
    }
    else if (is_nan_inf(literal))
    {
        double d;
        d = std::atof(literal.c_str());
        printNanInf(d);
    }
    else
    {
        print_imp();
    }
}