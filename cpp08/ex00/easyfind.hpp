#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind (T a, int search) 
{
    if (std::find(a.begin(), a.end(), search) != a.end())
        return (1);
    return(0);
}