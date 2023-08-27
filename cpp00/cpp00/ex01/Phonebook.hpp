#include <iostream>
#include <cstdio>
# include "Contact.hpp"
//using namespace std;


class PhoneBook
{
    private:
    Contact listContacts[8];
    int index;
    std::string add_aux(std::string);
    
    public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();
};
