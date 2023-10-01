#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <limits>

class Span 
{
private:
    std::vector<int> intVector;
    unsigned int n;
public:
    Span();
    Span(unsigned int n);
    Span(const Span&);
    ~Span();
    Span& operator=(const Span& span);
    void addNumber(int nbr);
    void addNumberRange(int begin, int end);
    void addNumberRange_times2(int begin, int end);
    int shortestSpan();
    int longestSpan();
};