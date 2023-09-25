#pragma once

#include <iostream>

template <typename T>
void print (const T& a) {
  std::cout << a << std::endl;
}

template <typename T, typename Func>
void iter (T *array, int len, Func f)
{
  for (int i = 0; i < len; i++)
    f(array[i]);
}

/* template <typename T>
void iter (T *array, int len, void(*fun)(T& a))
{
  for (int i = 0; i < len; i++)
    fun(array[i]);
}

template <typename T>
void iter (const T *array, int len, void(*fun)(const T& a))
{
  for (int i = 0; i < len; i++)
    fun(array[i]);
} */