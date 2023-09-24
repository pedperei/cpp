#include "iter.hpp"


int main( void ) 
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
}