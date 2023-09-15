#include "Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "1º Test:" << std::endl;
        try
        {
            std::cout << Bureaucrat("ze", 198) << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "2º Test:" << std::endl;
        try
        {
            std::cout << Bureaucrat("ze", 123) << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "3º Test:" << std::endl;
        try
        {
            Bureaucrat asd = Bureaucrat("ze", 150);
            std::cout << asd << std::endl;
            asd.decrementGrade();

        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "4º Test:" << std::endl;
        try
        {
            Bureaucrat asd = Bureaucrat("ze", 1);
            std::cout << asd << std::endl;
            asd.incrementGrade();

        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
}