#include "Contact.hpp"

Contact::Contact()
{

}
Contact::~Contact()
{

}

void Contact::setFirst_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::setLast_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::setNick_name(std::string nick_name)
{
    this->nick_name = nick_name;
}

void Contact::setPhone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setDarkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

std::string Contact::getFirst_name()
{
    return this->first_name;
}

std::string Contact::getLast_name()
{
    return this->last_name;
}

std::string Contact::getNick_name()
{
    return this->nick_name;
}

std::string Contact::getPhone_number()
{
    return this->phone_number;
}

std::string Contact::getDarkest_secret()
{
    return this->darkest_secret;
}

std::string treat_contact(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 10);
        str = str.replace(9,1,".");
    }
    return (str);
}

void Contact::print_contact(int index)
{
    std::cout << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << treat_contact(this->first_name);
    std::cout << "|" << std::setw(10) << treat_contact(this->last_name);
    std::cout << "|" << std::setw(10) << treat_contact(this->nick_name) << std::endl;
}