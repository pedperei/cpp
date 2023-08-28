#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
}
PhoneBook::~PhoneBook()
{

}

std::string add_aux(std::string field)
{
    std::string str = "";
    std::cout << field << std::endl;
    std::getline(std::cin, str);

    return (str);
}

int is_valid_contact(Contact contact)
{
    if (contact.getFirst_name().empty())
        return (0);
    if (contact.getLast_name().empty())
        return (0);
    if (contact.getNick_name().empty())
        return (0);
    if (contact.getPhone_number().empty())
        return (0);
    if (contact.getDarkest_secret().empty())
        return (0);
    return (1);
}

void PhoneBook::add()
{
    Contact contact;

    contact.setFirst_name(add_aux("First Name"));
    contact.setLast_name(add_aux("Last Name"));
    contact.setNick_name(add_aux("Nickname"));
    contact.setPhone_number(add_aux("Phone Number"));
    contact.setDarkest_secret(add_aux("Darkest Secret"));

    if(!is_valid_contact(contact))
    {
        std::cout << "Contact not added (at leat one field was empty)" << std::endl;
        return ;
    }
    else
        std::cout << "Contact added" << std::endl;
    if (this->index > 7)
        this->index = 0;
    listContacts[this->index] = contact;
    this->index++;
}


void PhoneBook::search(PhoneBook phonebook)
{
    int i = -1;
    std::string input;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    while (i < 8 && !phonebook.listContacts[++i].getFirst_name().empty())
    {
        phonebook.listContacts[i].print_contact(i);
    }
    std::cout << "Insert index:";
    std::getline(std::cin, input);
    if ((input == "0" || (atoi(input.c_str()) > 0 && atoi(input.c_str()) <= 7))
            && !phonebook.listContacts[atoi(input.c_str())].getFirst_name().empty())
    {
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        phonebook.listContacts[atoi(input.c_str())].print_contact(atoi(input.c_str()));
    }
    else
        std::cout << "index out of bounds" << std::endl;
}

