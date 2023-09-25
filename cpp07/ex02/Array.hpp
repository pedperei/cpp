#pragma once

#include <iostream>

template<typename T>
class Array 
{
private:
    unsigned int n;
    T* arr;
public:
    Array();
    Array(unsigned int n);
    Array(const Array&);
    ~Array();
    Array& operator=(const Array& array);
    T& operator[](unsigned int i);
    unsigned int size(void) const;
    T* getArr();
};