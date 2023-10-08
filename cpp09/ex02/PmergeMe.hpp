#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <limits>
#include <fstream>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <sstream>
#include <iterator>

class PmergeMe
{
public:
    std::vector<int> pmergeVector;
    std::list<int> pmergeList;
    PmergeMe();
    PmergeMe(const PmergeMe&);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& rpn);

    std::vector<int> merge_sort_vector(std::vector<int> pmergeVector);
    //std::vector<int> merge_vector(std::vector<int> vector1, std::vector<int> vector2);
    std::vector<int> insert_sort_vector(std::vector<int> pmergeVector);
    
    std::list<int> merge_sort_list(std::list<int> pmergeList);    
    //std::list<int> merge_list(std::list<int> vector1, std::list<int> vector2);
    std::list<int> insert_sort_list(std::list<int> pmergeList);

    int parse_input(std::string input);

    std::vector<int> getPmergeVector();
    std::list<int> getPmergeList();
    void setPmergeVector(std::vector<int> pmergeVector);
    void setPmergeList(std::list<int> pmergeList);



};