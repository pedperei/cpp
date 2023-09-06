#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) );
    std::cout << "\nComparison Operators" << std::endl;
    std::cout << (b>a) << std::endl;
    std::cout << (b == a) << std::endl;
    std::cout << (b>=a) << std::endl;
    std::cout << (b != a) << std::endl;
    std::cout << (b<=a) << std::endl;
    std::cout << (b < a) << std::endl;

    std::cout << "\nArithmetic Operators" << std::endl; 
    Fixed c(4);
    Fixed const d( Fixed( 5.2533333333f ) );
    std::cout << d*c << std::endl;
    std::cout << d/c << std::endl;
    std::cout << d+c << std::endl;
    std::cout << d-c << std::endl;

    std::cout << "\nIncrement Operators" << std::endl; 
    std::cout << c++ << std::endl;
    std::cout << c << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c << std::endl;

    std::cout << "\nDecrement Operators" << std::endl; 
    std::cout << c-- << std::endl;
    std::cout << c << std::endl;
    std::cout << --c << std::endl;
    std::cout << c << std::endl;
    std::cout << --c << std::endl;
    return 0;
}