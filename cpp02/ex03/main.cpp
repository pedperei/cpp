#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point A(0,0);
    Point B(0,3);
    Point C(3,0);

    Point P1(1.5,1.4);
    Point P2(4,0);
    
    if (bsp(A,B,C,P1))
        std::cout << "Point P1 is inside of the triangule" << std::endl;
    else   
        std::cout << "Point P1 is outside of the triangule" << std::endl;

    if (bsp(A,B,C,P2))
        std::cout << "Point P2 is inside of the triangule" << std::endl;
    else   
        std::cout << "Point P2 is outside of the triangule" << std::endl;

    return 0;
}