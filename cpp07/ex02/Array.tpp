#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array():n(0),arr(new T[0]){}

template<typename T>
Array<T>::Array(unsigned int n):n(n),arr(new T[n]){}

template<typename T>
Array<T>::Array(const Array& array)
{
    *this = array;
}

template<typename T>
Array& Array<T>::operator=(const Array& array)
{
    delete [] this->arr;
    this->arr = new T[arr.n];
    return (*this);
}
