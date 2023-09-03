#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point A(0,0);
    Point B(0,3);
    Point C(3,0);

    Point P1(1.5,1.5);
    Point P2(4,0);
    std::cout << bsp(A,B,C,P1) << std::endl;
    std::cout << bsp(A,B,C,P2) << std::endl;

    return 0;
}