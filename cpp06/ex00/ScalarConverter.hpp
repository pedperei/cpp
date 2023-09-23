#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
public:
    ScalarConverter &operator=(const ScalarConverter& scalarConverter);
    ~ScalarConverter();
    static void convert(std::string literal);
};

