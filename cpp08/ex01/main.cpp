#include "Span.hpp"

int main(void)
{
    {
        try
        {
            Span asd (10000);
            asd.addNumberRange(1, 10000);
            asd.addNumber(40000);
            std::cout << asd.shortestSpan() << std::endl;
            std::cout << asd.longestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Too many numbers inserted" << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Span asd (10000);
        asd.addNumberRange(1, 10000);
        std::cout << asd.shortestSpan() << std::endl;
        std::cout << asd.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        Span asd (10000);
        asd.addNumberRange_times2(1, 10000);
        std::cout << asd.shortestSpan() << std::endl;
        std::cout << asd.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        Span asd(10);

        try
        {
            Span asd(10);
            asd.addNumber(10);
            asd.addNumber(123);
            asd.addNumber(12);
            std::cout << asd.shortestSpan() << std::endl;
            std::cout << asd.longestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }  
}


/* int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
} */