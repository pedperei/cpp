#include "Array.hpp"

template<typename T>
Array<T>::Array():n(0),arr(new T[0]){}

template<typename T>
Array<T>::Array(unsigned int n):n(n),arr(new T[n]){}

template<typename T>
Array<T>::Array(const Array& array)
{
    this->arr = NULL;
    *this = array;
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& array)
{
    if (this != &array)
    {
        delete [] this->arr;
        this->n = array.n;
        this->arr = new T[array.n];
        for (unsigned int i = 0; i < array.n; i++)
            this->arr[i] = array.arr[i];
    }
    return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
    if(i < this->n)
        return (this->arr[i]);
    std::cout << "Index out of bounds" << std::endl;
    throw std::exception();
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return (this->n);
}

template<typename T>
T* Array<T>::getArr()
{
    return (this->arr);
}