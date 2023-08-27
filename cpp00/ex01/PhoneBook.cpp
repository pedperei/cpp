#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
}
PhoneBook::~PhoneBook()
{

}

std::string PhoneBook::add_aux(std::string field)
{
    std::string str = "";
    std::cout << field << std::endl;
    std::getline(std::cin, str);

    return (str);
}

void PhoneBook::add()
{
    Contact contact;

    contact.setFirst_name(add_aux("First Name"));
    contact.setLast_name(add_aux("Last Name"));
    contact.setNick_name(add_aux("Nickname"));
    contact.setPhone_number(add_aux("Phone Number"));
    contact.setDarkest_secret(add_aux("Darkest Secret"));
    
    if (this->index > 7)
        this->index = 0;
    listContacts[this->index] = contact;
    this->index++;
}

/* void PhoneBook::search(PhoneBook)
{

} */
