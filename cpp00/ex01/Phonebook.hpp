# include "Contact.hpp"
//using namespace std;


class PhoneBook
{
    private:
    Contact listContacts[8];
    int index;
    
    public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search(PhoneBook);
};
