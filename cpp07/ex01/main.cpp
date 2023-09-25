#include "iter.hpp"

void printMode(std::string &s) 
{
    std::cout << s << "_Mode" << std::endl;
}

int main( void ) {
    
    int intArr[] = {0, 1, 2, 3, 4};
    std::string stringArr[] = {"a", "b", "c", "d", "e"};
    double doubleArr[] = {0.5, 1.5, 2.5, 3.5, 4.5};


    int len = 5;

    ::iter(intArr, len, print<int>);
    std::cout << std::endl;
    ::iter(stringArr, len, print<std::string>);
    std::cout << std::endl;
    ::iter(doubleArr, len, print<double>);
    std::cout << std::endl;
    ::iter(stringArr, len, printMode);
    std::cout << std::endl;
    ::iter(intArr, len, print<const int>);

    return 0;
}

/*int main( void ) 
{
    int len = 10;
    std::string arr_str[len];
    for (int i = 0; i < len; i++)
        arr_str[i] = "Test";
    ::iter(arr_str, len, print<std::string>);

    int arr_int[len];
    for (int i = 0; i < len; i++)
        arr_int[i] = i;
    ::iter(arr_int, len, print<int>);
}*/