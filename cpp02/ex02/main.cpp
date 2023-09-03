#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) );
    std::cout << (b>a) << std::endl;
    std::cout << (b == a) << std::endl;
    std::cout << (b>=a) << std::endl;
    std::cout << (b != a) << std::endl;
    std::cout << (b<=a) << std::endl;
    std::cout << (b < a) << std::endl;
    
    a = b;
    std::cout << (b>a) << std::endl;
    std::cout << (b == a) << std::endl;
    std::cout << (b>=a) << std::endl;
    std::cout << (b != a) << std::endl;
    std::cout << (b<=a) << std::endl;
    std::cout << (b < a) << std::endl;

    Fixed c(4);
    Fixed const d( Fixed( 5.05f ) );
    std::cout << d*c << std::endl;
    std::cout << d/c << std::endl;
    std::cout << c++ << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c-- << std::endl;
    std::cout << --c << std::endl;
    std::cout << --c << std::endl;

    return 0;
}