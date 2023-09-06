#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl << std::endl << std::endl;

a.setRawBits(88);
Fixed d(a);
Fixed e;

e = d;
std::cout << a.getRawBits() << std::endl;
std::cout << d.getRawBits() << std::endl;
std::cout << e.getRawBits() << std::endl;
return 0;
}