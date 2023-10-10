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
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> pmergeVector;
    std::list<int> pmergeList;
public:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& rpn);

    std::vector<int> insert_sort_vector(std::vector<int> pmergeVector);
    std::vector<int> merge_insert_sort_vector(std::vector<int> pmergeVector, size_t k);

    
    std::list<int> insert_sort_list(std::list<int> pmergeList);
    std::list<int> merge_insert_sort_list(std::list<int> pmergeList, size_t k);


    int parse_input_vector(std::string input);
    int parse_input_list(std::string input);
    void display_contents(int pre_sort, double vector, double list);

    std::vector<int> getPmergeVector();
    std::list<int> getPmergeList();
    void setPmergeVector(std::vector<int> pmergeVector);
    void setPmergeList(std::list<int> pmergeList);
};