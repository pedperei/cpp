#pragma once

#include<iostream>
#include<stack>
#include<list>
#include<vector>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack&);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& mutantStack);
    typedef typename std::deque<T>::iterator iterator;
    iterator begin();
    iterator end();
};