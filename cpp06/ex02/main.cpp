#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>

Base* generate(void)
{
    std::srand(clock());
    int temp = std::rand();
    if (temp % 3 == 0)
        return (new A());
    else if (temp % 3 == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    Base *temp = p;
    temp = dynamic_cast<A*>(p);
    if (temp)
        std::cout << "Object Type A" << std::endl;
    temp = dynamic_cast<B*>(p);
    if (temp)
        std::cout << "Object Type B" << std::endl;
    temp = dynamic_cast<C*>(p);
    if (temp)
        std::cout << "Object Type C" << std::endl;
}

void identify(Base& p)
{
    Base temp = p;
    try
    {
        temp = dynamic_cast<A&>(p);
        std::cout << "Object Type A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        temp = dynamic_cast<B&>(p);
        std::cout << "Object Type B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        temp = dynamic_cast<C&>(p);
        std::cout << "Object Type C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }

} 

int main(void)
{
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
}