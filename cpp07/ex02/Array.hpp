#pragma once

#include <iostream>

template<typename T>
class Array 
{
private:
    unsigned int n;
    T* array;
public:
    Array();
    Array(unsigned int n);
    Array(const Array&);
    Array& operator=(const Array& array);
    int& operator[](int i);
    int size(void);
}