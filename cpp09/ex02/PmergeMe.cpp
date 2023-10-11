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
            std::iter_swap(temp, prev);
            temp = prev;
            if (prev != pmergeList.begin())
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
            std::iter_swap(temp, prev);
            temp = prev;
            if (prev != pmergeVector.begin())
                std::advance(prev, -1);
        }
    }
    return (pmergeVector);
}

std::list<int> PmergeMe::merge_insert_sort_list(std::list<int> pmergeList, size_t k)
{
    if (pmergeList.size() > k)
    {
        std::list<int>::iterator mid = pmergeList.begin();
        std::advance(mid, pmergeList.size() / 2);

        std::list<int> list1 (pmergeList.begin(), mid);
        std::list<int> list2 (mid, pmergeList.end());

        list1 = merge_insert_sort_list(list1, k);
        list2 = merge_insert_sort_list(list2, k);

        return(merge_list(list1, list2));
    }
    else
        return(insert_sort_list(pmergeList));
}

std::vector<int> PmergeMe::merge_insert_sort_vector(std::vector<int> pmergeVector, size_t k)
{
    if (pmergeVector.size() > k)
    {
        std::vector<int> vector1 (pmergeVector.begin(), pmergeVector.begin() + pmergeVector.size()/2);
        std::vector<int> vector2 (pmergeVector.begin() + pmergeVector.size()/2, pmergeVector.end());

        vector1 = merge_insert_sort_vector(vector1, k);
        vector2 = merge_insert_sort_vector(vector2, k);

        return (merge_vector(vector1, vector2));
    }
    else
        return(insert_sort_vector(pmergeVector));
}


bool is_digit(std::string input)
{
    for (size_t i = 0; i < input.size(); ++i) 
    {
        if (!(std::isdigit(input[i]) || ((input[i] == '+') && i == 0)))
            return (0);
    }
    return (1);
}

int PmergeMe::parse_input_vector(std::string input)
{
    std::stringstream s_input(input);
    std::string token;

    while (s_input >> token)
    {
        if(is_digit(token))
        {
            if (token.length() > 11)
                throw std::runtime_error("Error: invalid input " + token);
            double nbr = std::atof(token.c_str());
            if (nbr == 0)
                throw std::runtime_error("Error: invalid input " + token);
            if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
                throw std::runtime_error("Error: invalid input " + token);
            this->pmergeVector.push_back(static_cast<int>(nbr));
        }
        else
            throw std::runtime_error("Error: invalid input " + token);
    }
    return (1);
}

int PmergeMe::parse_input_list(std::string input)
{
    std::stringstream s_input(input);
    std::string token;

    while (s_input >> token)
    {
        if(is_digit(token))
        {
            if (token.length() > 11)
                throw std::runtime_error("Error: invalid input " + token);
            double nbr = std::atof(token.c_str());
            if (nbr == 0)
                throw std::runtime_error("Error: invalid input " + token);
            if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
                throw std::runtime_error("Error: invalid input " + token);
            this->pmergeList.push_back(static_cast<int>(nbr));
        }
        else
            throw std::runtime_error("Error: invalid input " + token);
    }
    return (1);
}

void PmergeMe::display_contents(int pre_sort, double vector, double list)
{

    if (pre_sort)
        std::cout << "Before: ";
    else
        std::cout << "After: ";
    std::list<int>::iterator end_vector = this->pmergeList.end();
    std::list<int>::iterator temp_vector = this->pmergeList.begin();
    for (; temp_vector != end_vector; temp_vector++) 
        std::cout << *temp_vector << " ";
    std::cout << std::endl;
    if (!pre_sort)
    {
        std::cout << "Time to process a range of " << this->pmergeList.size() << 
            " with std::list : " << list << " us" << std::endl;
        std::cout << "Time to process a range of " << this->pmergeVector.size() << 
            " with std::vector : " << vector << " us" << std::endl;
    }
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