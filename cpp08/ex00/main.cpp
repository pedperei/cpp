#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
    {
        std::vector<int> vector1;
        int size = 10;

        for (int i = 0; i < size; i++)
            vector1.push_back(i);

        if (easyfind(vector1, 2))
            std::cout << "Number Found" << std::endl;
        else
            std::cout << "Number Not Found" << std::endl;
        if (easyfind(vector1, 32))
            std::cout << "Number Found" << std::endl;
        else
            std::cout << "Number Not Found" << std::endl;
    }
    {
        std::vector<float> list1;
        int size = 10;

        for (int i = 0; i < size; i++)
            list1.push_back(i);

        if (easyfind(list1, 2))
            std::cout << "Number Found" << std::endl;
        else
            std::cout << "Number Not Found" << std::endl;
        if (easyfind(list1, 32))
            std::cout << "Number Found" << std::endl;
        else
            std::cout << "Number Not Found" << std::endl;
    }
}