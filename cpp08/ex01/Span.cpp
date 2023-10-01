#include "Span.hpp"

Span::Span():n(0){}

Span::Span(unsigned int n):n(n){}

Span::Span(const Span& span)
{
    *this = span;
}

Span::~Span(){}

Span& Span::operator=(const Span& span)
{
    if (this != &span)
    {
        this->intVector = span.intVector;
        this->n = span.n;
    }
    return (*this);
}

void Span::addNumber(int nbr)
{
    if (this->intVector.size() < this->n)
        this->intVector.push_back(nbr);
    else
        throw std::exception();
}

void Span::addNumberRange(int begin, int end)
{
    if ((this->intVector.size() + std::abs(end - begin)) < this->n)
    {
        for (int i = begin; i <= end ; i++)
            this->intVector.push_back(i);
    }
    else    
        throw std::exception();
}

void Span::addNumberRange_times2(int begin, int end)
{
    if ((this->intVector.size() + std::abs(end - begin)) < this->n)
    {
        for (int i = begin; i <= end ; i++)
            this->intVector.push_back(i * 2);
    }
    else    
        throw std::exception();
}

int Span::shortestSpan()
{
    int min_span = std::numeric_limits<int>::max();
    int temp;

    if(this->intVector.size() < 2)
        throw std::exception();
    std::sort(this->intVector.begin(), this->intVector.end());
    std::vector<int>::iterator it;
    for (it = this->intVector.begin(); it != intVector.end(); it++)
    {
        temp = std::abs((*(it + 1)) - (*it));
        if (temp < min_span)
            min_span = temp;
        if (std::distance(it, intVector.end()) == 2)
            break;
    }
    return (min_span);
}

int Span::longestSpan()
{
    int max_span;

    if(this->intVector.size() < 2)
        throw std::exception();
    std::vector<int>::iterator max = std::max_element(intVector.begin(), intVector.end());
    std::vector<int>::iterator min = std::min_element(intVector.begin(), intVector.end());

    max_span = std::abs(*max - *min);
    return (max_span);
}
