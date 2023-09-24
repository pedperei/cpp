#pragma once

#include <iostream>

template <typename T>
void print (const T& a) {
  std::cout << a << std::endl;
}

template <typename T>
void iter (T *array, int len, void(*fun)(const T& a))
{
  for (int i = 0; i < len; i++)
    fun(array[i]);
}
