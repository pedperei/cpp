#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe)
{
    *this = pmergeMe;
}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe)
{
    if (this != &pmergeMe)
    {
        this->pmergeVector = pmergeMe.pmergeVector;
        this->pmergeList = pmergeMe.pmergeList;
    }
    return (*this);
}

std::vector<int> merge_vector(std::vector<int> vector1, std::vector<int> vector2)
{
    std::vector<int> temp;

    while (!vector1.empty() && !vector2.empty())
    {
        if(vector1[0] > vector2[0])
        {
            temp.push_back(vector2[0]);
            vector2.erase(vector2.begin());
        }
        else
        {
            temp.push_back(vector1[0]);
            vector1.erase(vector1.begin());
        }
    }

    while (!vector1.empty())
    {
        temp.push_back(vector1[0]);
        vector1.erase(vector1.begin());
    }
    while (!vector2.empty())
    {
        temp.push_back(vector2[0]);
        vector2.erase(vector2.begin());
    }
    
    return (temp);
}

std::vector<int> PmergeMe::merge_sort_vector(std::vector<int> pmergeVector)
{
    if (pmergeVector.size() == 1)
        return (pmergeVector);
    
    std::vector<int> vector1 (pmergeVector.begin(), pmergeVector.begin() + pmergeVector.size()/2);
    std::vector<int> vector2 (pmergeVector.begin() + pmergeVector.size()/2, pmergeVector.end());

    vector1 = merge_sort_vector(vector1);
    vector2 = merge_sort_vector(vector2);

    return (merge_vector(vector1, vector2));
}

std::list<int> merge_list(std::list<int> list1, std::list<int> list2)
{
    std::list<int> temp;

    while (!list1.empty() && !list2.empty())
    {
        if(list1.front() > list2.front())
        {
            temp.push_back(list2.front());
            list2.erase(list2.begin());
        }
        else
        {
            temp.push_back(list1.front());
            list1.erase(list1.begin());
        }
    }

    while (!list1.empty())
    {
        temp.push_back(list1.front());
        list1.erase(list1.begin());
    }
    while (!list2.empty())
    {
        temp.push_back(list2.front());
        list2.erase(list2.begin());
    }
    
    return (temp);
}

std::list<int> PmergeMe::merge_sort_list(std::list<int> pmergeList)
{
    if (pmergeList.size() == 1)
        return (pmergeList);
    
    std::list<int>::iterator mid = pmergeList.begin();
    std::advance(mid, pmergeList.size() / 2);

    std::list<int> list1 (pmergeList.begin(), mid);
    std::list<int> list2 (mid, pmergeList.end());

    list1 = merge_sort_list(list1);
    list2 = merge_sort_list(list2);

    return (merge_list(list1, list2));
}

std::list<int> PmergeMe::insert_sort_list(std::list<int> pmergeList)
{
    std::list<int>::iterator it = pmergeList.begin();;
    std::list<int>::iterator prev;
    std::list<int>::iterator temp;
    it++;
    for (; it != pmergeList.end(); it++)
    {
        temp = it;
        prev = temp;
        std::advance(prev, -1);
        while (*prev > *temp)
        {
            std::swap(*temp, *prev);
            prev = temp;
            std::advance(prev, -1);
        }
    }
    return (pmergeList);
}

std::vector<int> PmergeMe::insert_sort_vector(std::vector<int> pmergeVector)
{
    std::vector<int>::iterator it = pmergeVector.begin();
    std::vector<int>::iterator prev;
    std::vector<int>::iterator temp;
    it++;
    for (; it != pmergeVector.end(); it++)
    {
        temp = it;
        prev = temp;
        std::advance(prev, -1);
        while (*prev > *temp)
        {
            std::swap(*temp, *prev);
            prev = temp;
            std::advance(prev, -1);
        }
    }
    return (pmergeVector);
}

bool is_digit(std::string input)
{
    for (size_t i = 0; i < input.size(); ++i) 
    {
        if (!std::isdigit(input[i]))
            return (0);
    }
    return (1);
}

int PmergeMe::parse_input(std::string input)
{
    std::stringstream s_input(input);
    std::string token;

    while (s_input >> token)
    {
        if(is_digit(token))
        {
            this->pmergeList.push_back(std::atoi(token.c_str()));
            this->pmergeVector.push_back(std::atoi(token.c_str()));
        }
        else
            return (0);
    }
    return (1);
}

std::vector<int> PmergeMe::getPmergeVector()
{
    return (this->pmergeVector);
}

std::list<int> PmergeMe::getPmergeList()
{
    return (this->pmergeList);
}

void PmergeMe::setPmergeVector(std::vector<int> pmergeVector)
{
    this->pmergeVector = pmergeVector;
}

void PmergeMe::setPmergeList(std::list<int> pmergeList)
{
    this->pmergeList = pmergeList;
}