#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter &operator=(const ScalarConverter& scalarConverter);
    ~ScalarConverter();
    static void convert(std::string literal);
};

