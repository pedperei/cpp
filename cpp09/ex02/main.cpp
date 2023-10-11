#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
        return (0);
    else
    {
        PmergeMe *test = new PmergeMe();
        try
        {
            std::stringstream s_input;
            int i = 1;
            while (argv[i])
            {
                s_input << argv[i] << " ";
                i++;
            }
            std::clock_t list_s_time = std::clock();
            test->parse_input_list(s_input.str());
            size_t k = test->getPmergeList().size() * 0.2;
            if (k < 2)
                k = 1;
            test->display_contents(1, 0, 0);
            test->setPmergeList(test->merge_insert_sort_list(test->getPmergeList(), k));
            std::clock_t list_e_time = std::clock();

            std::clock_t vector_s_time = std::clock();
            test->parse_input_vector(s_input.str());
            test->setPmergeVector(test->merge_insert_sort_vector(test->getPmergeVector(), k));
            
            std::clock_t vector_e_time = std::clock();

            double vector_time = static_cast<double>(vector_e_time - vector_s_time) / CLOCKS_PER_SEC * 1000000;
            double list_time = static_cast<double>(list_e_time - list_s_time) / CLOCKS_PER_SEC * 1000000;

            test->display_contents(0, vector_time, list_time);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            delete test;
            return (0);
        }
        delete test;
    }
}