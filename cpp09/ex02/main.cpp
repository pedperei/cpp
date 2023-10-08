#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
        return (0);
    else
    {
        PmergeMe *test = new PmergeMe();

        test->parse_input(argv[1]);

        std::list<int>::iterator begin_list = test->pmergeList.begin();
        std::list<int>::iterator end_list = test->pmergeList.end();
        std::list<int>::iterator temp_list = test->pmergeList.begin();
        for (; temp_list != end_list; temp_list++) 
            std::cout << *temp_list << " ";
        std::cout << std::endl;

        std::vector<int>::iterator begin_vector = test->pmergeVector.begin();
        std::vector<int>::iterator end_vector = test->pmergeVector.end();
        std::vector<int>::iterator temp_vector = test->pmergeVector.begin();
        for (; temp_vector != end_vector; temp_vector++) 
            std::cout << *temp_vector << " ";
        std::cout << std::endl;

        //test->setPmergeList(test->merge_sort_list(test->pmergeList));
        //test->setPmergeVector(test->merge_sort_vector(test->pmergeVector));

        test->setPmergeList(test->insert_sort_list(test->pmergeList));
        test->setPmergeVector(test->insert_sort_vector(test->pmergeVector));

        std::cout << std::endl;
        begin_list = test->pmergeList.begin();
        end_list = test->pmergeList.end();
        temp_list = test->pmergeList.begin();
        for (; temp_list != end_list; temp_list++) 
            std::cout << *temp_list << " ";
        std::cout << std::endl;

        begin_vector = test->pmergeVector.begin();
        end_vector = test->pmergeVector.end();
        temp_vector = test->pmergeVector.begin();
        for (; temp_vector != end_vector; temp_vector++) 
            std::cout << *temp_vector << " ";
        std::cout << std::endl;
    }
}