#include "Array.tpp"

int main (void)
{
    {
        Array<int> asd =Array<int>(32);
        for (int i = 1; i < 33; i++)
            asd[i - 1] = i;
        unsigned int i = -1;
        while (++i < asd.size())
            std::cout << asd[i] << std::endl;
        std::cout << std::endl;
        std::cout << "size: " << asd.size() << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        Array<std::string> asd = Array<std::string>(5);
        for (int i = 0; i < 5; i++)
            asd[i] = "test";
        unsigned int i = -1;
        Array<std::string> test = asd;
        for (int i = 0; i < 5; i++)
            asd[i] = "asd";
        while (++i < asd.size())
            std::cout << asd[i] << std::endl;
        i = -1;
        while (++i < test.size())
            std::cout << test[i] << std::endl;
        std::cout << std::endl;
        std::cout << "size: " << asd.size() << std::endl;
        std::cout << "size: " << test.size() << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        try
        {
            Array<float> asd(30);
            asd[176] = 123;
        }
        catch (std::exception &e)
        {
            (void) e;
        }
    }
    std::cout << std::endl << std::endl;
    {
        try
        {
            Array<double> asd(30);
            asd[100] = 123;
        }
        catch (std::exception &e)
        {
            (void) e;
        }
    }
}