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

void Contact::print_contact(void)
{
    std::cout << "first_name" << this->first_name << std::endl;
    std::cout << "last_name" << this->last_name << std::endl;
    std::cout << "nick_name" << this->nick_name << std::endl;
    std::cout << "phone_number" << this->phone_number << std::endl;
    std::cout << "darkest_secret" << this->darkest_secret << std::endl;
}